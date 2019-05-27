#pragma once

namespace Kursach_CLR {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AddPlaneTypeForm
	/// </summary>
	public ref class AddPlaneTypeForm : public System::Windows::Forms::Form
	{
	public:
		String^ title;
		int capacity;
		Decimal baggage_capacity;

		bool dialogResult = false;

		AddPlaneTypeForm(void)
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
		~AddPlaneTypeForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  titleTextBox;
	private: System::Windows::Forms::TextBox^  capacityTextBox;
	private: System::Windows::Forms::TextBox^  baggageCapacityTextBox;
	private: System::Windows::Forms::Button^  addButton;
	protected:

	protected:




	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	protected:

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
			this->titleTextBox = (gcnew System::Windows::Forms::TextBox());
			this->capacityTextBox = (gcnew System::Windows::Forms::TextBox());
			this->baggageCapacityTextBox = (gcnew System::Windows::Forms::TextBox());
			this->addButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// titleTextBox
			// 
			this->titleTextBox->Location = System::Drawing::Point(78, 6);
			this->titleTextBox->Name = L"titleTextBox";
			this->titleTextBox->Size = System::Drawing::Size(194, 20);
			this->titleTextBox->TabIndex = 0;
			// 
			// capacityTextBox
			// 
			this->capacityTextBox->Location = System::Drawing::Point(97, 32);
			this->capacityTextBox->Name = L"capacityTextBox";
			this->capacityTextBox->Size = System::Drawing::Size(175, 20);
			this->capacityTextBox->TabIndex = 1;
			// 
			// baggageCapacityTextBox
			// 
			this->baggageCapacityTextBox->Location = System::Drawing::Point(137, 58);
			this->baggageCapacityTextBox->Name = L"baggageCapacityTextBox";
			this->baggageCapacityTextBox->Size = System::Drawing::Size(135, 20);
			this->baggageCapacityTextBox->TabIndex = 2;
			// 
			// addButton
			// 
			this->addButton->Location = System::Drawing::Point(15, 84);
			this->addButton->Name = L"addButton";
			this->addButton->Size = System::Drawing::Size(257, 23);
			this->addButton->TabIndex = 3;
			this->addButton->Text = L"Добавить";
			this->addButton->UseVisualStyleBackColor = true;
			this->addButton->Click += gcnew System::EventHandler(this, &AddPlaneTypeForm::addButton_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(60, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Название:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 35);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(79, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Вместимость:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 61);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(119, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Вместимость багажа:";
			// 
			// AddPlaneTypeForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 118);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->addButton);
			this->Controls->Add(this->baggageCapacityTextBox);
			this->Controls->Add(this->capacityTextBox);
			this->Controls->Add(this->titleTextBox);
			this->Name = L"AddPlaneTypeForm";
			this->Text = L"AddPlaneTypeForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: bool CheckValues();
	private: System::Void addButton_Click(System::Object^  sender, System::EventArgs^  e);
	};
}
