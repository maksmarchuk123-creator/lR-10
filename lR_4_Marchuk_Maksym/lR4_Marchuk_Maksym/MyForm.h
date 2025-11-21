#pragma once

namespace lR4MarchukMaksym {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Windows::Forms::DataVisualization::Charting;

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
			if (components) delete components;
		}

	private:
		System::ComponentModel::Container^ components;

		System::Windows::Forms::MenuStrip^ menuStrip1;
		System::Windows::Forms::ToolStripMenuItem^ menuRozrahunok;
		System::Windows::Forms::ToolStripMenuItem^ menuClear;
		System::Windows::Forms::ToolStripMenuItem^ menuCalc;
		System::Windows::Forms::ToolStripMenuItem^ menuExit;

		System::Windows::Forms::ContextMenuStrip^ contextMenu1;
		System::Windows::Forms::ToolStripMenuItem^ contextClear;
		System::Windows::Forms::ToolStripMenuItem^ contextCalc;

		System::Windows::Forms::ToolStrip^ toolStrip1;
		System::Windows::Forms::ToolStripButton^ toolClear;
		System::Windows::Forms::ToolStripButton^ toolCalc;
		System::Windows::Forms::ToolStripButton^ toolExit;

		System::Windows::Forms::DataGridView^ dataGridView1;
		System::Windows::Forms::PictureBox^ pictureBox1;
		Chart^ chart1;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = gcnew System::ComponentModel::Container();

			this->menuStrip1 = gcnew System::Windows::Forms::MenuStrip();
			this->menuRozrahunok = gcnew System::Windows::Forms::ToolStripMenuItem();
			this->menuClear = gcnew System::Windows::Forms::ToolStripMenuItem();
			this->menuCalc = gcnew System::Windows::Forms::ToolStripMenuItem();
			this->menuExit = gcnew System::Windows::Forms::ToolStripMenuItem();

			this->contextMenu1 = gcnew System::Windows::Forms::ContextMenuStrip(this->components);
			this->contextClear = gcnew System::Windows::Forms::ToolStripMenuItem();
			this->contextCalc = gcnew System::Windows::Forms::ToolStripMenuItem();

			this->toolStrip1 = gcnew System::Windows::Forms::ToolStrip();
			this->toolClear = gcnew System::Windows::Forms::ToolStripButton();
			this->toolCalc = gcnew System::Windows::Forms::ToolStripButton();
			this->toolExit = gcnew System::Windows::Forms::ToolStripButton();

			this->dataGridView1 = gcnew System::Windows::Forms::DataGridView();
			this->pictureBox1 = gcnew System::Windows::Forms::PictureBox();
			this->chart1 = gcnew Chart();

			ChartArea^ chartArea1 = gcnew ChartArea();
			Series^ series1 = gcnew Series();

			this->SuspendLayout();

			
			this->menuRozrahunok->Text = L"Розрахунок";
			this->menuClear->Text = L"Очистити";
			this->menuClear->ShortcutKeys = Keys::Alt | Keys::O;
			this->menuCalc->Text = L"Розрахувати";
			this->menuCalc->ShortcutKeys = Keys::Control | Keys::Alt | Keys::C;
			this->menuExit->Text = L"Вихід";
			this->menuExit->ShortcutKeys = Keys::Alt | Keys::F4;

			
			try {
				this->menuClear->Image = Image::FromFile("icons\\clear.png");
				this->menuCalc->Image = Image::FromFile("icons\\calc.png");
				this->menuExit->Image = Image::FromFile("icons\\exit.png");

				this->toolClear->Image = Image::FromFile("icons\\clear.png");
				this->toolCalc->Image = Image::FromFile("icons\\calc.png");
				this->toolExit->Image = Image::FromFile("icons\\exit.png");

				this->toolClear->DisplayStyle = ToolStripItemDisplayStyle::Image;
				this->toolCalc->DisplayStyle = ToolStripItemDisplayStyle::Image;
				this->toolExit->DisplayStyle = ToolStripItemDisplayStyle::Image;

				this->toolClear->ToolTipText = L"Очистити";
				this->toolCalc->ToolTipText = L"Розрахувати";
				this->toolExit->ToolTipText = L"Вийти";
			}
			catch (Exception^ ex) {
				MessageBox::Show(L"Не вдалося завантажити іконки: " + ex->Message);
			}

			this->menuRozrahunok->DropDownItems->AddRange(
				gcnew cli::array<ToolStripItem^>{ this->menuClear, this->menuCalc, this->menuExit });
			this->menuStrip1->Items->AddRange(
				gcnew cli::array<ToolStripItem^>{ this->menuRozrahunok });

			
			this->contextClear->Text = L"Очистити";
			this->contextCalc->Text = L"Розрахувати";
			this->contextMenu1->Items->AddRange(
				gcnew cli::array<ToolStripItem^>{ this->contextClear, this->contextCalc });

			
			this->toolStrip1->Items->AddRange(
				gcnew cli::array<ToolStripItem^>{ this->toolClear, this->toolCalc, this->toolExit });

			
			this->dataGridView1->Location = Point(12, 50);
			this->dataGridView1->Size = Drawing::Size(400, 300);
			this->dataGridView1->ContextMenuStrip = this->contextMenu1;

			
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			series1->ChartArea = L"ChartArea1";
			series1->Name = L"Series1";
			this->chart1->Series->Add(series1);
			this->chart1->Location = Point(430, 50);
			this->chart1->Size = Drawing::Size(420, 300);

			
			this->pictureBox1->Location = Point(12, 360);
			this->pictureBox1->Size = Drawing::Size(100, 80);
			this->pictureBox1->BorderStyle = BorderStyle::FixedSingle;
			this->pictureBox1->BackColor = Color::DimGray;

			
			this->BackColor = Color::FromArgb(20, 20, 20);  
			this->ForeColor = Color::White;
			this->ClientSize = Drawing::Size(880, 480);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->toolStrip1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Text = L"MyForm";

			
			this->menuStrip1->BackColor = Color::FromArgb(30, 30, 30);
			this->menuStrip1->ForeColor = Color::White;

			
			this->toolStrip1->BackColor = Color::FromArgb(30, 30, 30);
			this->toolStrip1->ForeColor = Color::White;
			this->toolStrip1->GripStyle = ToolStripGripStyle::Hidden;

			
			this->dataGridView1->BackgroundColor = Color::FromArgb(25, 25, 25);
			this->dataGridView1->DefaultCellStyle->BackColor = Color::FromArgb(35, 35, 35);
			this->dataGridView1->DefaultCellStyle->ForeColor = Color::White;
			this->dataGridView1->ColumnHeadersDefaultCellStyle->BackColor = Color::FromArgb(45, 45, 45);
			this->dataGridView1->ColumnHeadersDefaultCellStyle->ForeColor = Color::White;
			this->dataGridView1->EnableHeadersVisualStyles = false;

			
			this->chart1->BackColor = Color::FromArgb(25, 25, 25);
			this->chart1->ChartAreas[0]->BackColor = Color::FromArgb(25, 25, 25);
			this->chart1->Series[0]->Color = Color::Lime;

			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion
	};
}
