#pragma once
#include "Database.h"

namespace Kursach_CLR
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public Form
	{
		Database^ db = gcnew Database();

	public:
		MainForm(void)
		{
			InitializeComponent();
			for (int i = 0; i < groupsDataGridView->Columns->Count; ++i)
			{
				groupsDataGridView->Columns[i]->SortMode = DataGridViewColumnSortMode::NotSortable;
			}
			Load += gcnew System::EventHandler(this, &Kursach_CLR::MainForm::OnLoad);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}















	private: System::Windows::Forms::DataGridView^  planesDataGridView;



	private: System::Windows::Forms::Button^  addPlaneButton;
	private: System::Windows::Forms::Button^  addPassagerButton;
	private: System::Windows::Forms::Button^  groupDistributingButton;
	private: System::Windows::Forms::Button^  addNewPlaneTypeButton;












	private: System::Windows::Forms::DataGridViewTextBoxColumn^  plane_title;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  planes_count;



	private: System::Windows::Forms::DataGridViewTextBoxColumn^  flightCost;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  passagersBaggageWeight;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  baggageCapacity;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  passagersCount;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  planeCapacity;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  planeTitle;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  arrivalCountry;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  arrivalCity;
	private: System::Windows::Forms::DataGridView^  flightsGridView;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  baggage_weight;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  passagers_count;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  arrival_city;
	private: System::Windows::Forms::DataGridView^  groupsDataGridView;































	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->planesDataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->planesDataGridView->AutoGenerateColumns = false;
			this->plane_title = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->planes_count = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->addPlaneButton = (gcnew System::Windows::Forms::Button());
			this->addPassagerButton = (gcnew System::Windows::Forms::Button());
			this->groupDistributingButton = (gcnew System::Windows::Forms::Button());
			this->addNewPlaneTypeButton = (gcnew System::Windows::Forms::Button());
			this->flightCost = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->passagersBaggageWeight = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->baggageCapacity = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->passagersCount = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->planeCapacity = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->planeTitle = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->arrivalCountry = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->arrivalCity = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->flightsGridView = (gcnew System::Windows::Forms::DataGridView());
			this->baggage_weight = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->passagers_count = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->arrival_city = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->groupsDataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->groupsDataGridView->AutoGenerateColumns = false;
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->planesDataGridView))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->flightsGridView))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->groupsDataGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// planesDataGridView
			// 
			this->planesDataGridView->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->planesDataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->planesDataGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->plane_title,
					this->planes_count
			});
			this->planesDataGridView->Location = System::Drawing::Point(1082, 12);
			this->planesDataGridView->Name = L"planesDataGridView";
			this->planesDataGridView->Size = System::Drawing::Size(246, 582);
			this->planesDataGridView->TabIndex = 2;
			// 
			// plane_title
			// 
			this->plane_title->DataPropertyName = L"title";
			this->plane_title->HeaderText = L"Название самолёта";
			this->plane_title->Name = L"plane_title";
			// 
			// planes_count
			// 
			this->planes_count->DataPropertyName = L"planes_count";
			this->planes_count->HeaderText = L"Количество самолётов";
			this->planes_count->Name = L"planes_count";
			// 
			// addPlaneButton
			// 
			this->addPlaneButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->addPlaneButton->Location = System::Drawing::Point(410, 600);
			this->addPlaneButton->Name = L"addPlaneButton";
			this->addPlaneButton->Size = System::Drawing::Size(193, 49);
			this->addPlaneButton->TabIndex = 3;
			this->addPlaneButton->Text = L"Добавить самолёт";
			this->addPlaneButton->UseVisualStyleBackColor = true;
			this->addPlaneButton->Click += gcnew System::EventHandler(this, &MainForm::addPlaneButton_Click);
			// 
			// addPassagerButton
			// 
			this->addPassagerButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->addPassagerButton->Location = System::Drawing::Point(12, 600);
			this->addPassagerButton->Name = L"addPassagerButton";
			this->addPassagerButton->Size = System::Drawing::Size(193, 49);
			this->addPassagerButton->TabIndex = 4;
			this->addPassagerButton->Text = L"Добавить пассажира";
			this->addPassagerButton->UseVisualStyleBackColor = true;
			this->addPassagerButton->Click += gcnew System::EventHandler(this, &MainForm::addPassagerButton_Click);
			// 
			// groupDistributingButton
			// 
			this->groupDistributingButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->groupDistributingButton->Location = System::Drawing::Point(211, 600);
			this->groupDistributingButton->Name = L"groupDistributingButton";
			this->groupDistributingButton->Size = System::Drawing::Size(193, 49);
			this->groupDistributingButton->TabIndex = 5;
			this->groupDistributingButton->Text = L"Распределить группу";
			this->groupDistributingButton->UseVisualStyleBackColor = true;
			this->groupDistributingButton->Click += gcnew System::EventHandler(this, &MainForm::groupDistributingButton_Click);
			// 
			// addNewPlaneTypeButton
			// 
			this->addNewPlaneTypeButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->addNewPlaneTypeButton->Location = System::Drawing::Point(609, 600);
			this->addNewPlaneTypeButton->Name = L"addNewPlaneTypeButton";
			this->addNewPlaneTypeButton->Size = System::Drawing::Size(193, 49);
			this->addNewPlaneTypeButton->TabIndex = 6;
			this->addNewPlaneTypeButton->Text = L"Добавить новый вид самолётов";
			this->addNewPlaneTypeButton->UseVisualStyleBackColor = true;
			this->addNewPlaneTypeButton->Click += gcnew System::EventHandler(this, &MainForm::addNewPlaneTypeButton_Click);
			// 
			// flightCost
			// 
			this->flightCost->DataPropertyName = L"cost";
			this->flightCost->HeaderText = L"Стоимость рейса";
			this->flightCost->Name = L"flightCost";
			this->flightCost->Width = 80;
			// 
			// passagersBaggageWeight
			// 
			this->passagersBaggageWeight->DataPropertyName = L"baggage_weight";
			this->passagersBaggageWeight->HeaderText = L"Общий вес багажа";
			this->passagersBaggageWeight->Name = L"passagersBaggageWeight";
			this->passagersBaggageWeight->Width = 70;
			// 
			// baggageCapacity
			// 
			this->baggageCapacity->DataPropertyName = L"baggage_capacity";
			this->baggageCapacity->HeaderText = L"Вместимость багажного отсека";
			this->baggageCapacity->Name = L"baggageCapacity";
			this->baggageCapacity->Width = 80;
			// 
			// passagersCount
			// 
			this->passagersCount->DataPropertyName = L"passagers_count";
			this->passagersCount->HeaderText = L"Кол-во пассажиров";
			this->passagersCount->Name = L"passagersCount";
			this->passagersCount->Width = 70;
			// 
			// planeCapacity
			// 
			this->planeCapacity->DataPropertyName = L"capacity";
			this->planeCapacity->HeaderText = L"Вместимость самолёта";
			this->planeCapacity->Name = L"planeCapacity";
			this->planeCapacity->Width = 85;
			// 
			// planeTitle
			// 
			this->planeTitle->DataPropertyName = L"title";
			this->planeTitle->HeaderText = L"Самолёт";
			this->planeTitle->Name = L"planeTitle";
			// 
			// arrivalCountry
			// 
			this->arrivalCountry->DataPropertyName = L"country_name";
			this->arrivalCountry->HeaderText = L"Страна посадки";
			this->arrivalCountry->Name = L"arrivalCountry";
			// 
			// arrivalCity
			// 
			this->arrivalCity->DataPropertyName = L"city_name";
			this->arrivalCity->HeaderText = L"Город посадки";
			this->arrivalCity->Name = L"arrivalCity";
			// 
			// flightsGridView
			// 
			this->flightsGridView->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->flightsGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->flightsGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(8) {
				this->arrivalCity,
					this->arrivalCountry, this->planeTitle, this->planeCapacity, this->passagersCount, this->baggageCapacity, this->passagersBaggageWeight,
					this->flightCost
			});
			this->flightsGridView->Location = System::Drawing::Point(12, 12);
			this->flightsGridView->Name = L"flightsGridView";
			this->flightsGridView->Size = System::Drawing::Size(731, 582);
			this->flightsGridView->TabIndex = 0;
			// 
			// baggage_weight
			// 
			this->baggage_weight->DataPropertyName = L"baggage_weight";
			this->baggage_weight->HeaderText = L"Общий вес багажа";
			this->baggage_weight->Name = L"baggage_weight";
			this->baggage_weight->Width = 70;
			// 
			// passagers_count
			// 
			this->passagers_count->DataPropertyName = L"passagers_count";
			this->passagers_count->HeaderText = L"Кол-во пассажиров";
			this->passagers_count->Name = L"passagers_count";
			this->passagers_count->Width = 80;
			// 
			// arrival_city
			// 
			this->arrival_city->DataPropertyName = L"city_name";
			this->arrival_city->HeaderText = L"Город посадки";
			this->arrival_city->Name = L"arrival_city";
			// 
			// groupsDataGridView
			// 
			this->groupsDataGridView->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->groupsDataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->groupsDataGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->arrival_city,
					this->passagers_count, this->baggage_weight
			});
			this->groupsDataGridView->Location = System::Drawing::Point(767, 12);
			this->groupsDataGridView->Name = L"groupsDataGridView";
			this->groupsDataGridView->Size = System::Drawing::Size(295, 582);
			this->groupsDataGridView->TabIndex = 1;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1342, 661);
			this->Controls->Add(this->addNewPlaneTypeButton);
			this->Controls->Add(this->groupDistributingButton);
			this->Controls->Add(this->addPassagerButton);
			this->Controls->Add(this->addPlaneButton);
			this->Controls->Add(this->planesDataGridView);
			this->Controls->Add(this->groupsDataGridView);
			this->Controls->Add(this->flightsGridView);
			this->Name = L"MainForm";
			this->Text = L"Аэропорт";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->planesDataGridView))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->flightsGridView))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->groupsDataGridView))->EndInit();
			this->ResumeLayout(false);
		}
#pragma endregion
	private: KeyValuePair<int, int> searchPlane(DataTable^ group, DataTable^ planes, int passagers_count, Decimal Baggage_weight);
	private: System::Void groupDistributingButton_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void addPlaneButton_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void addNewPlaneTypeButton_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void OnLoad(System::Object^ sender, System::EventArgs^ args);
	private: System::Void FillFlightsDataGridView();
	private: System::Void FillGroupsDataGridView();
	private: System::Void FillPlanesDataGridView();
	private: System::Void FillAllDataGridViews();
	private: System::Void ExceptionMessage(System::Exception^ ex);
	private: System::Void addPassagerButton_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void clearFlights();
	private: System::Void refreshFlights();
	private: System::Void clearGroups();
	private: System::Void refreshGroups();
	private: System::Void clearAirportPlanes();
	private: System::Void refreshAirportPlanes();
	};
}
