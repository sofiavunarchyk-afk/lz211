#pragma once

namespace lz311 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;

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
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 16, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(238, 47);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(756, 42);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Обробка масиву чисел з файлу numbers.txt";
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(47, 131);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(528, 400);
			this->richTextBox1->TabIndex = 1;
			this->richTextBox1->Text = L"";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->button1->Location = System::Drawing::Point(737, 149);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(481, 169);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Зчитати файл та обчислити";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(262, 604);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(347, 32);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Добуток від\'ємних чисел:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(638, 609);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(245, 26);
			this->textBox1->TabIndex = 4;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1344, 775);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		// 1. Очищаємо поля від попередніх даних (якщо натискаємо не вперше)
		richTextBox1->Clear();
		textBox1->Clear();

		try {
			// 2. Зчитуємо весь текст з файлу (використовую IO::File для надійності)
			String^ fileContent = System::IO::File::ReadAllText("numbers.txt");

			// 3. Виводимо всі зчитані числа у RichTextBox, щоб ви бачили їх на екрані
			richTextBox1->Text = "Числа з файлу:\n" + fileContent;

			// 4. Розбиваємо текст на окремі числа (видаляємо пробіли і нові рядки)
			array<String^>^ stringNumbers = fileContent->Split(
				gcnew array<Char>{' ', '\n', '\r', '\t'},
				System::StringSplitOptions::RemoveEmptyEntries
			);

			int product = 1;          // Змінна для добутку
			bool hasNegative = false; // Прапорець: чи є взагалі від'ємні числа

			// 5. Проходимося по всіх знайдених числах
			for (int i = 0; i < stringNumbers->Length; i++) {
				// Перетворюємо текст на число
				int number = Convert::ToInt32(stringNumbers[i]);

				// Якщо число від'ємне
				if (number < 0) {
					product *= number;    // Множимо
					hasNegative = true;   // Запам'ятовуємо, що знайшли хоча б одне
				}
			}

			// 6. Виводимо готовий результат у TextBox1
			if (hasNegative) {
				textBox1->Text = product.ToString();
			}
			else {
				textBox1->Text = "Немає від'ємних чисел";
			}
		}
		catch (System::IO::FileNotFoundException^) {
			// Якщо забули створити файл або він не в тій папці
			MessageBox::Show("Помилка: Файл 'numbers.txt' не знайдено!\nПеревірте, чи він лежить у папці проєкту.", "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		catch (FormatException^) {
			// Якщо у файлі випадково написали букви
			MessageBox::Show("Помилка: У файлі є недопустимі символи. Мають бути лише цілі числа через пробіл.", "Помилка вводу", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		catch (Exception^ ex) {
			// Будь-яка інша непередбачувана помилка
			MessageBox::Show("Сталася помилка: " + ex->Message, "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
};
}
