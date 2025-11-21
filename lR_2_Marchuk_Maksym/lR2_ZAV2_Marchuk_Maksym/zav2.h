#pragma once
#include "clas2.h"

namespace lr3mm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class zav2 : public System::Windows::Forms::Form
	{
	public:
		zav2(void)
		{
			InitializeComponent();
		}

	protected:
		~zav2()
		{
			if (components)
				delete components;
		}

	private:
		System::Windows::Forms::Label^ label1;
		System::Windows::Forms::TextBox^ txtRadius;
		System::Windows::Forms::Button^ btnCalc;
		System::Windows::Forms::Label^ lblLength;
		System::Windows::Forms::Label^ lblArea;

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txtRadius = (gcnew System::Windows::Forms::TextBox());
			this->btnCalc = (gcnew System::Windows::Forms::Button());
			this->lblLength = (gcnew System::Windows::Forms::Label());
			this->lblArea = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(20, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(82, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Введіть радіус:";
			// 
			// txtRadius
			// 
			this->txtRadius->Location = System::Drawing::Point(120, 17);
			this->txtRadius->Name = L"txtRadius";
			this->txtRadius->Size = System::Drawing::Size(100, 20);
			this->txtRadius->TabIndex = 1;
			// 
			// btnCalc
			// 
			this->btnCalc->Location = System::Drawing::Point(20, 60);
			this->btnCalc->Name = L"btnCalc";
			this->btnCalc->Size = System::Drawing::Size(200, 25);
			this->btnCalc->TabIndex = 2;
			this->btnCalc->Text = L"Обчислити";
			this->btnCalc->Click += gcnew System::EventHandler(this, &zav2::btnCalc_Click);
			// 
			// lblLength
			// 
			this->lblLength->AutoSize = true;
			this->lblLength->Location = System::Drawing::Point(20, 110);
			this->lblLength->Name = L"lblLength";
			this->lblLength->Size = System::Drawing::Size(60, 13);
			this->lblLength->TabIndex = 3;
			this->lblLength->Text = L"Довжина: ";
			// 
			// lblArea
			// 
			this->lblArea->AutoSize = true;
			this->lblArea->Location = System::Drawing::Point(20, 140);
			this->lblArea->Name = L"lblArea";
			this->lblArea->Size = System::Drawing::Size(48, 13);
			this->lblArea->TabIndex = 4;
			this->lblArea->Text = L"Площа: ";
			// 
			// zav2
			// 
			this->ClientSize = System::Drawing::Size(300, 200);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txtRadius);
			this->Controls->Add(this->btnCalc);
			this->Controls->Add(this->lblLength);
			this->Controls->Add(this->lblArea);
			this->Name = L"zav2";
			this->Text = L"Завдання 2";
			this->Load += gcnew System::EventHandler(this, &zav2::zav2_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		System::Void btnCalc_Click(System::Object^ sender, System::EventArgs^ e)
		{
			try
			{
				double r = Convert::ToDouble(txtRadius->Text);
				clas2 calc;
				double length = calc.CalcLength(r);
				double area = calc.CalcArea(r);
				lblLength->Text = "Довжина: " + length.ToString("F2");
				lblArea->Text = "Площа: " + area.ToString("F2");
			}
			catch (FormatException^)
			{
				MessageBox::Show("Введіть коректне число!", "Помилка");
			}
		}
	private: System::Void zav2_Load(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
