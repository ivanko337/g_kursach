#include "AddAirportPlane.h"

namespace Kursach_CLR
{
	void AddAirportPlane::OnLoad(System::Object^  sender, System::EventArgs^  e)
	{
		DataSet^ planes = db->loadPlanes();
		planesTitlesComboBox->DisplayMember = "title";
		planesTitlesComboBox->DataSource = planes->Tables["Planes"];
	}

	bool AddAirportPlane::CheckCount()
	{
		try
		{
			Convert::ToDecimal(planesCountTextBox->Text);
			return true;
		}
		catch(Exception^)
		{
			return false;
		}
	}

	void AddAirportPlane::addButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (!CheckCount() && planesTitlesComboBox->SelectedIndex == -1)
		{
			MessageBox::Show("¬ведите корректные значени€", "WARNING", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		DataRow^ currRow = ((DataTable^)planesTitlesComboBox->DataSource)->Rows[planesTitlesComboBox->SelectedIndex];
		plane_id = Convert::ToInt32(currRow["id"]);
		count = Convert::ToDouble(planesCountTextBox->Text);

		dialogReult = true;

		Close();
	}
}