#include "AddPlaneTypeForm.h"

namespace Kursach_CLR
{
	bool AddPlaneTypeForm::CheckValues()
	{
		bool res = (titleTextBox->Text->Replace(" ", "")) != "";

		try
		{
			Convert::ToDecimal(capacityTextBox->Text);
			Convert::ToDecimal(baggageCapacityTextBox->Text);
			res = res && true;
		}
		catch (Exception^)
		{
			return false;
		}

		return res;
	}

	void AddPlaneTypeForm::addButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (!CheckValues())
		{
			MessageBox::Show("¬ведите корректные значени€", "WARNING", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}

		title = titleTextBox->Text;
		capacity = Convert::ToInt32(capacityTextBox->Text);
		baggage_capacity = Convert::ToDecimal(baggageCapacityTextBox->Text);

		dialogResult = true;

		Close();
	}
}