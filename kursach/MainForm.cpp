#include "MainForm.h"
#include "AddPassagerForm.h"
#include "AddAirportPlane.h"
#include "AddPlaneTypeForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Kursach_CLR::MainForm form;
	Application::Run(%form);
}

namespace Kursach_CLR
{
	void MainForm::ExceptionMessage(System::Exception^ ex)
	{
		MessageBox::Show(ex->Message, gcnew String("ERROR"), MessageBoxButtons::OK, MessageBoxIcon::Error);
	}

	KeyValuePair<int, int> MainForm::searchPlane(DataTable^ group, DataTable^ planes, int passagers_count, Decimal baggage_weight)
	{
		int planesTypesCount = planes->Rows->Count;

		if (planesTypesCount == 1)
		{
			DataRow^ row = planes->Rows[0];

			int planeId = Convert::ToInt32(row["plane_id"]);
			int planesCount = Convert::ToInt32(row["planes_count"]);
			int passagersCapacity = Convert::ToInt32(row["capacity"]);
			Decimal planeBaggageCapacity = Convert::ToDecimal(row["baggage_capacity"]);

			if (passagersCapacity * planesCount < passagers_count && planeBaggageCapacity * planesCount < baggage_weight && planesCount == 1)
			{
				MessageBox::Show("Невозможно распределить группу, т.к. не хватает самолётов", "WARNING", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return KeyValuePair<int, int>(-1, -1);
			}
			else
			{
				for (int i = 1; i <= planesCount; ++i)
				{
					if (passagersCapacity * i >= passagers_count && planeBaggageCapacity * i >= baggage_weight)
					{
						return KeyValuePair<int, int>(planeId, i);
					}
				}
				return KeyValuePair<int, int>(-1, -1);
			}
		}

		for (int i = 0; i < planesTypesCount; ++i)
		{
			DataRow^ row = planes->Rows[i];

			int planeId = Convert::ToInt32(row["plane_id"]);
			int planesCount = Convert::ToInt32(row["planes_count"]);
			int passagersCapacity = Convert::ToInt32(row["capacity"]);
			Decimal planeBaggageCapacity = Convert::ToDecimal(row["baggage_capacity"]);

			for (int i = 1; i < planesCount; ++i)
			{
				if (passagersCapacity >= passagers_count && planeBaggageCapacity >= baggage_weight)
				{
					return KeyValuePair<int, int>(planeId, i);
				}
			}
		}

		MessageBox::Show("Невозможно распределить группу, т.к. не хватает самолётов", "WARNING", MessageBoxButtons::OK, MessageBoxIcon::Warning);

		return KeyValuePair<int, int>(-1, -1);
	}

	void MainForm::groupDistributingButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		DataGridViewSelectedCellCollection^ selectedCells = groupsDataGridView->SelectedCells;
		
		if (selectedCells->Count == 0)
		{
			MessageBox::Show("Вы ничего не выбрали", "WARNING", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		DataGridViewCell^ cell = (DataGridViewCell^)selectedCells[0];
		int rowIndex = cell->RowIndex;
		DataRow^ currRow;
		try
		{
			currRow = ((DataTable^)groupsDataGridView->DataSource)->Rows[rowIndex];
		}
		catch (IndexOutOfRangeException^)
		{
			MessageBox::Show("Нет групп", "WARNING", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		int arrival_city = Convert::ToInt32(currRow["arrival_city"]);
		
		try
		{
			Decimal city_cost = db->loadCityCost(arrival_city);
			DataTable^ currGroup = db->loadGroup(arrival_city)->Tables["Passagers"];
			DataTable^ airportPlanes = db->loadDescSortedAirportPlanes()->Tables["AirportPlanes"];

			int passagersCount = currGroup->Rows->Count;
			Decimal baggageWeight = db->loadGroupBaggageWeight(arrival_city);

			// первый - id самолёта, второй - кол-во таких самолётов
			KeyValuePair<int, int> planes = searchPlane(currGroup, airportPlanes, passagersCount, baggageWeight);

			if (planes.Key == -1)
			{
				return;
			}

			db->insertIntoDistGroups(arrival_city, passagersCount, baggageWeight);
			int groupId = db->loadLastDistGroupId();

			db->insertIntoFlights(planes.Key, groupId, arrival_city);

			db->deleteGroup(arrival_city, passagersCount);
			db->deleteAirportPlanes(planes.Key, planes.Value);

			refreshFlights();
			refreshGroups();
			refreshAirportPlanes();
		}
		catch (Exception^ ex)
		{
			ExceptionMessage(ex);
		}
	}

	void MainForm::addPlaneButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		AddAirportPlane^ form = gcnew AddAirportPlane();
		form->ShowDialog();

		if (!form->dialogReult)
		{
			return;
		}

		int plane_id = form->plane_id;
		int count = form->count;

		db->insertIntoAirportPlanes(plane_id, count);

		refreshAirportPlanes();
	}

	void MainForm::addPassagerButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		AddPassagerForm^ form = gcnew AddPassagerForm();
		form->ShowDialog();

		int arr_city = form->city_id;
		Decimal bagg_weight = form->baggage_weight;

		if (arr_city <= 0)
		{
			return;
		}

		try
		{
			db->insertIntoPassagers(arr_city, bagg_weight);
			refreshGroups();
		}
		catch (Exception^ ex)
		{
			ExceptionMessage(ex);
		}
	}

	void MainForm::addNewPlaneTypeButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		AddPlaneTypeForm^ form = gcnew AddPlaneTypeForm();
		form->ShowDialog();

		if (!form->dialogResult)
		{
			return;
		}

		String^ title = form->title;
		int capacity = form->capacity;
		Decimal bagg_capacity = form->baggage_capacity;

		try
		{
			db->insertIntoPlanes(title, capacity, bagg_capacity);
		}
		catch (Exception^ ex)
		{
			ExceptionMessage(ex);
		}
	}

	void MainForm::OnLoad(System::Object^ sender, System::EventArgs^ args)
	{
		try
		{
			FillAllDataGridViews();
		}
		catch (Exception^ ex)
		{
			ExceptionMessage(ex);
		}
	}

	void MainForm::FillAllDataGridViews()
	{
		FillFlightsDataGridView();
		FillGroupsDataGridView();
		FillPlanesDataGridView();
	}

	void MainForm::clearFlights()
	{
		((DataTable^)flightsGridView->DataSource)->Rows->Clear();
	}

	void MainForm::FillFlightsDataGridView()
	{
		DataSet^ flights = db->loadFlights();
		flightsGridView->DataSource = flights->Tables["Flights"];
	}

	void MainForm::clearGroups()
	{
		((DataTable^)groupsDataGridView->DataSource)->Rows->Clear();
	}

	void MainForm::FillGroupsDataGridView()
	{
		DataSet^ groups = db->loadGroups();
		groupsDataGridView->DataSource = groups->Tables[gcnew String("Groups")];
	}

	void MainForm::clearAirportPlanes()
	{
		((DataTable^)planesDataGridView->DataSource)->Rows->Clear();
	}

	void MainForm::FillPlanesDataGridView()
	{
		DataSet^ airportPlanes = db->loadAirportPlanes();
		planesDataGridView->DataSource = airportPlanes->Tables["AirportPlanes"];
		if (airportPlanes->Tables["AirportPlanes"]->Rows->Count == 0)
		{
			MessageBox::Show("Все самолёты закончились", "WARNING", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}

	void MainForm::refreshAirportPlanes()
	{
		clearAirportPlanes();
		FillPlanesDataGridView();
	}

	void MainForm::refreshFlights()
	{
		clearFlights();
		FillFlightsDataGridView();
	}

	void MainForm::refreshGroups()
	{
		clearGroups();
		FillGroupsDataGridView();
	}
}