#pragma once

#include "Database.h"

namespace Kursach_CLR {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AddPassagerForm
	/// </summary>
	public ref class AddPassagerForm : public System::Windows::Forms::Form
	{
		Database^ db = gcnew Database();

	public:
		int city_id;
		Decimal baggage_weight;

		AddPassagerForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AddPassagerForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::TextBox^  baggage_weightTextBox;
	protected:

	protected:

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  addButton;
	private: System::Windows::Forms::ComboBox^  arrivalCityComboBox;





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
			this->baggage_weightTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->addButton = (gcnew System::Windows::Forms::Button());
			this->arrivalCityComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// baggage_weightTextBox
			// 
			this->baggage_weightTextBox->Location = System::Drawing::Point(106, 33);
			this->baggage_weightTextBox->Name = L"baggage_weightTextBox";
			this->baggage_weightTextBox->Size = System::Drawing::Size(172, 20);
			this->baggage_weightTextBox->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(82, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Город посадки";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 36);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(66, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Вес багажа";
			// 
			// addButton
			// 
			this->addButton->Location = System::Drawing::Point(15, 59);
			this->addButton->Name = L"addButton";
			this->addButton->Size = System::Drawing::Size(263, 23);
			this->addButton->TabIndex = 4;
			this->addButton->Text = L"Добавить";
			this->addButton->UseVisualStyleBackColor = true;
			this->addButton->Click += gcnew System::EventHandler(this, &AddPassagerForm::addButton_Click);
			// 
			// arrivalCityComboBox
			// 
			this->arrivalCityComboBox->FormattingEnabled = true;
			this->arrivalCityComboBox->Location = System::Drawing::Point(106, 6);
			this->arrivalCityComboBox->Name = L"arrivalCityComboBox";
			this->arrivalCityComboBox->Size = System::Drawing::Size(172, 21);
			this->arrivalCityComboBox->TabIndex = 5;
			// 
			// AddPassagerForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(290, 92);
			this->Controls->Add(this->arrivalCityComboBox);
			this->Controls->Add(this->addButton);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->baggage_weightTextBox);
			this->Name = L"AddPassagerForm";
			this->Text = L"Добавить пассажира";
			this->Load += gcnew System::EventHandler(this, &AddPassagerForm::AddPassagerForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void AddPassagerForm_Load(System::Object^  sender, System::EventArgs^  e)
	{
		DataSet^ cities = db->loadCities();
		arrivalCityComboBox->DisplayMember = "city_name";
		arrivalCityComboBox->DataSource = cities->Tables["Cities"];
	}

	private: System::Boolean checkValues()
	{
		bool res = true;

		res = res && (arrivalCityComboBox->SelectedIndex != -1);

		try
		{
			Convert::ToDecimal(baggage_weightTextBox->Text);
		}
		catch (Exception^)
		{
			res = false;
		}

		return res;
	}

	private: System::Void addButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (!checkValues())
		{
			MessageBox::Show("Введите корректные значения", "WARNING", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		DataRow^ row = ((DataTable^)arrivalCityComboBox->DataSource)->Rows[arrivalCityComboBox->SelectedIndex];
		city_id = Convert::ToInt32(row["id"]);
		baggage_weight = Convert::ToDecimal(baggage_weightTextBox->Text);
		Close();
	}
	};
}
