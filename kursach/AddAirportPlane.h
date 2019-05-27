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
	/// Summary for AddAirportPlane
	/// </summary>
	public ref class AddAirportPlane : public System::Windows::Forms::Form
	{
		Database^ db = gcnew Database();

	public:
		int plane_id;
		int count;
		bool dialogReult = false;

		AddAirportPlane(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			Load += gcnew System::EventHandler(this, &Kursach_CLR::AddAirportPlane::OnLoad);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AddAirportPlane()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ComboBox^  planesTitlesComboBox;

	private: System::Windows::Forms::TextBox^  planesCountTextBox;


	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  addButton;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->planesTitlesComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->planesCountTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->addButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(109, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Название самолёта";
			// 
			// planesTitlesComboBox
			// 
			this->planesTitlesComboBox->FormattingEnabled = true;
			this->planesTitlesComboBox->Location = System::Drawing::Point(128, 10);
			this->planesTitlesComboBox->Name = L"planesTitlesComboBox";
			this->planesTitlesComboBox->Size = System::Drawing::Size(190, 21);
			this->planesTitlesComboBox->TabIndex = 1;
			// 
			// planesCountTextBox
			// 
			this->planesCountTextBox->Location = System::Drawing::Point(142, 48);
			this->planesCountTextBox->Name = L"planesCountTextBox";
			this->planesCountTextBox->Size = System::Drawing::Size(176, 20);
			this->planesCountTextBox->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 51);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(124, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Количество самолётов";
			// 
			// addButton
			// 
			this->addButton->Location = System::Drawing::Point(13, 74);
			this->addButton->Name = L"addButton";
			this->addButton->Size = System::Drawing::Size(305, 22);
			this->addButton->TabIndex = 4;
			this->addButton->Text = L"Добавить";
			this->addButton->UseVisualStyleBackColor = true;
			this->addButton->Click += gcnew System::EventHandler(this, &AddAirportPlane::addButton_Click);
			// 
			// AddAirportPlane
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(330, 108);
			this->Controls->Add(this->addButton);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->planesCountTextBox);
			this->Controls->Add(this->planesTitlesComboBox);
			this->Controls->Add(this->label1);
			this->Name = L"AddAirportPlane";
			this->Text = L"Добавить самолёт";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: bool CheckCount();
	private: System::Void addButton_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void OnLoad(System::Object^  sender, System::EventArgs^  e);
	};
}
