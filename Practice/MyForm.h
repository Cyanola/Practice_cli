#pragma once
#include "Functions.h"
namespace Practice {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
			Application::Exit();
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ Step;


	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->Step = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Location = System::Drawing::Point(59, 9);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(457, 412);
			this->panel1->TabIndex = 1;
			this->panel1->Click += gcnew System::EventHandler(this, &MyForm::panel1_Click);
			// 
			// Step
			// 
			this->Step->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Step->Location = System::Drawing::Point(402, 443);
			this->Step->Name = L"Step";
			this->Step->Size = System::Drawing::Size(114, 34);
			this->Step->TabIndex = 1;
			this->Step->Text = L"’од";
			this->Step->UseVisualStyleBackColor = true;
			this->Step->Click += gcnew System::EventHandler(this, &MyForm::Step_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(346, 443);
			this->textBox1->MaximumSize = System::Drawing::Size(50, 34);
			this->textBox1->MinimumSize = System::Drawing::Size(50, 34);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(50, 34);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(610, 489);
			this->Controls->Add(this->Step);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->textBox1);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		   private: System::Void Step_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void panel1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Setup();
		while (!gameOver)
		{
			//label1->Clear();
			for (int i = 0; i < width + 2; i++)
				panel1->Text = "#";
			panel1->Text = "\n";

			for (int i = 0; i < height; i++)
			{
				for (int j = 0; j < width; j++)
				{
					if (j == 0)
						panel1->Text = "#";
					if (i == y && j == x)
						panel1->Text = "O";
					else if (i == fruitY && j == fruitX)
						panel1->Text = "*";
					else
					{
						bool print = false;
						for (int k = 0; k < nTail; k++)
						{
							if (tailX[k] == j && tailY[k] == i)
							{
								panel1->Text = "o";
								print = true;
							}
						}
						if (!print)
							panel1->Text = " ";
					}
					if (j == width - 1)
						panel1->Text = "#";
				}
				panel1->Text += "\n";
			}

			for (int i = 0; i < width + 2; i++)
				panel1->Text = "#";
			panel1->Text = "\n";
			panel1->Text = "Score:" + score +"\n";
			Step_Click(sender, e);

			Logic();
			Sleep(90); //sleep(10);
		}
	}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
