#pragma once
#include <cmath> 

namespace lr3mm {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;


    public ref class MyForm : public System::Windows::Forms::Form
    {
    public:
        MyForm(void)
        {
            InitializeComponent();
        }

    protected:
        ~MyForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:

        TextBox^ txtK;
        TextBox^ txtP;
        TextBox^ txtX;
        TextBox^ txtD;
        Button^ btnCalc;
        Label^ lblResult;
        Label^ lblK;
        Label^ lblP;
        Label^ lblX;
        Label^ lblD;

        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->txtK = (gcnew TextBox());
            this->txtP = (gcnew TextBox());
            this->txtX = (gcnew TextBox());
            this->txtD = (gcnew TextBox());
            this->btnCalc = (gcnew Button());
            this->lblResult = (gcnew Label());
            this->lblK = (gcnew Label());
            this->lblP = (gcnew Label());
            this->lblX = (gcnew Label());
            this->lblD = (gcnew Label());

            this->SuspendLayout();

            this->lblK->Location = System::Drawing::Point(20, 20);
            this->lblK->Size = System::Drawing::Size(100, 20);
            this->lblK->Text = L"k (число):";

            this->txtK->Location = System::Drawing::Point(130, 18);
            this->txtK->Size = System::Drawing::Size(150, 22);
            this->txtK->Text = L"";

            this->lblP->Location = System::Drawing::Point(20, 60);
            this->lblP->Size = System::Drawing::Size(100, 20);
            this->lblP->Text = L"p (число):";

            this->txtP->Location = System::Drawing::Point(130, 58);
            this->txtP->Size = System::Drawing::Size(150, 22);
            this->txtP->Text = L"";

            this->lblX->Location = System::Drawing::Point(20, 100);
            this->lblX->Size = System::Drawing::Size(100, 20);
            this->lblX->Text = L"x (число):";
 

            this->txtX->Location = System::Drawing::Point(130, 98);
            this->txtX->Size = System::Drawing::Size(150, 22);
            this->txtX->Text = L"";

            this->lblD->Location = System::Drawing::Point(20, 140);
            this->lblD->Size = System::Drawing::Size(100, 20);
            this->lblD->Text = L"d (число):";

            this->txtD->Location = System::Drawing::Point(130, 138);
            this->txtD->Size = System::Drawing::Size(150, 22);
            this->txtD->Text = L"";

            this->btnCalc->Location = System::Drawing::Point(130, 180);
            this->btnCalc->Size = System::Drawing::Size(120, 30);
            this->btnCalc->Text = L"Обчислити";
            this->btnCalc->Click += gcnew System::EventHandler(this, &MyForm::btnCalc_Click);

            this->lblResult->Location = System::Drawing::Point(20, 230);
            this->lblResult->Size = System::Drawing::Size(400, 30);
            this->lblResult->Text = L"Результат: ";


            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(460, 300);
            this->Controls->Add(this->lblK);
            this->Controls->Add(this->txtK);
            this->Controls->Add(this->lblP);
            this->Controls->Add(this->txtP);
            this->Controls->Add(this->lblX);
            this->Controls->Add(this->txtX);
            this->Controls->Add(this->lblD);
            this->Controls->Add(this->txtD);
            this->Controls->Add(this->btnCalc);
            this->Controls->Add(this->lblResult);
            this->Name = L"MyForm";
            this->Text = L"Обчислення Q";
            this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion

    private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
    }

    private: System::Void btnCalc_Click(System::Object^ sender, System::EventArgs^ e) {
        try {
            
            double k = System::Convert::ToDouble(this->txtK->Text);
            double p = System::Convert::ToDouble(this->txtP->Text);
            double x = System::Convert::ToDouble(this->txtX->Text);
            double d = System::Convert::ToDouble(this->txtD->Text);

            double inside = k + 2.6 * p * std::sin(k);

            if (inside < 0.0) {
                this->lblResult->Text = L"Помилка: підкореневий вираз < 0 (неможливо обчислити sqrt).";
                return;
            }

            double numerator = std::sqrt(inside);
            double denominator = x - std::pow(d, 3);

            if (std::fabs(denominator) < 1e-12) {
                this->lblResult->Text = L"Помилка: знаменник дорівнює 0 (або дуже близький до 0).";
                return;
            }

            double Q = numerator / denominator;
            
            this->lblResult->Text = L"Результат: " + Q.ToString("F6");
        }
        catch (FormatException^) {
            this->lblResult->Text = L"Помилка: введіть коректні числа у всі поля.";
        }
        catch (OverflowException^) {
            this->lblResult->Text = L"Помилка: введене число занадто велике або занадто мале.";
        }
        catch (Exception^ ex) {
            this->lblResult->Text = L"Помилка: " + ex->Message;
        }
    }
    };
}
