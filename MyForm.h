#pragma once

namespace MpiMethod {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
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
		/// Освободить все используемые ресурсы.
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
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownN;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownM;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownEps;
	private: System::Windows::Forms::NumericUpDown^ numericUpDownNiter;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::DataGridView^ dataGridView1;

	private: System::Windows::Forms::RadioButton^ MPIradio;
	private: System::Windows::Forms::RadioButton^ radioTestTask;


	private: System::Windows::Forms::RadioButton^ radioMainTask;

	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::RadioButton^ Grad;

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::GroupBox^ groupBox4;
	private: System::Windows::Forms::RadioButton^ TableVtest;
	private: System::Windows::Forms::RadioButton^ TableUtest;


	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::RadioButton^ TableV2;

	private: System::Windows::Forms::RadioButton^ TableV;





	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->numericUpDownN = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDownM = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDownEps = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDownNiter = (gcnew System::Windows::Forms::NumericUpDown());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->MPIradio = (gcnew System::Windows::Forms::RadioButton());
			this->radioTestTask = (gcnew System::Windows::Forms::RadioButton());
			this->radioMainTask = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->TableVtest = (gcnew System::Windows::Forms::RadioButton());
			this->TableUtest = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->TableV2 = (gcnew System::Windows::Forms::RadioButton());
			this->TableV = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->Grad = (gcnew System::Windows::Forms::RadioButton());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownN))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownM))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownEps))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownNiter))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(47, 49);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(65, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"a = 1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(148, 49);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(66, 29);
			this->label2->TabIndex = 1;
			this->label2->Text = L"b = 2";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(233, 49);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(64, 29);
			this->label3->TabIndex = 2;
			this->label3->Text = L"c = 1";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(332, 49);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(66, 29);
			this->label4->TabIndex = 3;
			this->label4->Text = L"d = 2";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(47, 110);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(117, 29);
			this->label5->TabIndex = 4;
			this->label5->Text = L"u(a, y) = 0";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(332, 110);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(118, 29);
			this->label6->TabIndex = 5;
			this->label6->Text = L"u(b, y) = 0";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(47, 183);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(227, 29);
			this->label7->TabIndex = 6;
			this->label7->Text = L"u(x, c) = sin^2(pi * x)";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(332, 183);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(301, 29);
			this->label8->TabIndex = 7;
			this->label8->Text = L"u(x, d) = cosh((x-1)(x-2)) - 1";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label9->Location = System::Drawing::Point(47, 264);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(217, 29);
			this->label9->TabIndex = 8;
			this->label9->Text = L"f(x, y) = arctan(x / y)";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label10->Location = System::Drawing::Point(332, 264);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(251, 29);
			this->label10->TabIndex = 9;
			this->label10->Text = L"u(test) = exp(x^2 - y^2)";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label11->Location = System::Drawing::Point(47, 517);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(284, 29);
			this->label11->TabIndex = 10;
			this->label11->Text = L"Число разбиений по X:";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label12->Location = System::Drawing::Point(47, 568);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(283, 29);
			this->label12->TabIndex = 11;
			this->label12->Text = L"Число разбиений по Y:";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label13->Location = System::Drawing::Point(47, 618);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(220, 29);
			this->label13->TabIndex = 12;
			this->label13->Text = L"Точность метода:";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label14->Location = System::Drawing::Point(47, 668);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(255, 29);
			this->label14->TabIndex = 13;
			this->label14->Text = L"Ограничение шагов:";
			// 
			// numericUpDownN
			// 
			this->numericUpDownN->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->numericUpDownN->Location = System::Drawing::Point(368, 516);
			this->numericUpDownN->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->numericUpDownN->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDownN->Name = L"numericUpDownN";
			this->numericUpDownN->Size = System::Drawing::Size(136, 30);
			this->numericUpDownN->TabIndex = 14;
			this->numericUpDownN->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			// 
			// numericUpDownM
			// 
			this->numericUpDownM->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->numericUpDownM->Location = System::Drawing::Point(368, 567);
			this->numericUpDownM->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->numericUpDownM->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDownM->Name = L"numericUpDownM";
			this->numericUpDownM->Size = System::Drawing::Size(136, 30);
			this->numericUpDownM->TabIndex = 15;
			this->numericUpDownM->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			// 
			// numericUpDownEps
			// 
			this->numericUpDownEps->DecimalPlaces = 8;
			this->numericUpDownEps->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->numericUpDownEps->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 131072 });
			this->numericUpDownEps->Location = System::Drawing::Point(368, 618);
			this->numericUpDownEps->Name = L"numericUpDownEps";
			this->numericUpDownEps->Size = System::Drawing::Size(136, 30);
			this->numericUpDownEps->TabIndex = 16;
			this->numericUpDownEps->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 524288 });
			// 
			// numericUpDownNiter
			// 
			this->numericUpDownNiter->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->numericUpDownNiter->Location = System::Drawing::Point(368, 667);
			this->numericUpDownNiter->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100000, 0, 0, 0 });
			this->numericUpDownNiter->Name = L"numericUpDownNiter";
			this->numericUpDownNiter->Size = System::Drawing::Size(136, 30);
			this->numericUpDownNiter->TabIndex = 17;
			this->numericUpDownNiter->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label15->Location = System::Drawing::Point(47, 348);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(427, 29);
			this->label15->TabIndex = 18;
			this->label15->Text = L"Начальное приближение - нулевое";
			// 
			// dataGridView1
			// 
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::DisplayedCellsExceptHeaders;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(735, 49);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(756, 328);
			this->dataGridView1->TabIndex = 19;
			// 
			// MPIradio
			// 
			this->MPIradio->AutoSize = true;
			this->MPIradio->Checked = true;
			this->MPIradio->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->MPIradio->Location = System::Drawing::Point(0, 1);
			this->MPIradio->Name = L"MPIradio";
			this->MPIradio->Size = System::Drawing::Size(273, 29);
			this->MPIradio->TabIndex = 20;
			this->MPIradio->TabStop = true;
			this->MPIradio->Text = L"Метод простых итераций";
			this->MPIradio->UseVisualStyleBackColor = true;
			// 
			// radioTestTask
			// 
			this->radioTestTask->AutoSize = true;
			this->radioTestTask->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioTestTask->Location = System::Drawing::Point(0, 104);
			this->radioTestTask->Name = L"radioTestTask";
			this->radioTestTask->Size = System::Drawing::Size(189, 29);
			this->radioTestTask->TabIndex = 21;
			this->radioTestTask->Text = L"Тестовая задача";
			this->radioTestTask->UseVisualStyleBackColor = true;
			// 
			// radioMainTask
			// 
			this->radioMainTask->AutoSize = true;
			this->radioMainTask->Checked = true;
			this->radioMainTask->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioMainTask->Location = System::Drawing::Point(2, 0);
			this->radioMainTask->Name = L"radioMainTask";
			this->radioMainTask->Size = System::Drawing::Size(191, 29);
			this->radioMainTask->TabIndex = 22;
			this->radioMainTask->TabStop = true;
			this->radioMainTask->Text = L"Основная задача";
			this->radioMainTask->UseVisualStyleBackColor = true;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->groupBox4);
			this->groupBox1->Controls->Add(this->groupBox3);
			this->groupBox1->Controls->Add(this->radioMainTask);
			this->groupBox1->Controls->Add(this->radioTestTask);
			this->groupBox1->Location = System::Drawing::Point(735, 502);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(258, 221);
			this->groupBox1->TabIndex = 23;
			this->groupBox1->TabStop = false;
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->TableVtest);
			this->groupBox4->Controls->Add(this->TableUtest);
			this->groupBox4->Location = System::Drawing::Point(18, 139);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(124, 76);
			this->groupBox4->TabIndex = 30;
			this->groupBox4->TabStop = false;
			// 
			// TableVtest
			// 
			this->TableVtest->AutoSize = true;
			this->TableVtest->Checked = true;
			this->TableVtest->Location = System::Drawing::Point(6, 21);
			this->TableVtest->Name = L"TableVtest";
			this->TableVtest->Size = System::Drawing::Size(69, 21);
			this->TableVtest->TabIndex = 27;
			this->TableVtest->TabStop = true;
			this->TableVtest->Text = L"V(x, y)";
			this->TableVtest->UseVisualStyleBackColor = true;
			// 
			// TableUtest
			// 
			this->TableUtest->AutoSize = true;
			this->TableUtest->Location = System::Drawing::Point(6, 48);
			this->TableUtest->Name = L"TableUtest";
			this->TableUtest->Size = System::Drawing::Size(70, 21);
			this->TableUtest->TabIndex = 28;
			this->TableUtest->TabStop = true;
			this->TableUtest->Text = L"U(x, y)";
			this->TableUtest->UseVisualStyleBackColor = true;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->TableV2);
			this->groupBox3->Controls->Add(this->TableV);
			this->groupBox3->Location = System::Drawing::Point(18, 35);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(124, 63);
			this->groupBox3->TabIndex = 29;
			this->groupBox3->TabStop = false;
			// 
			// TableV2
			// 
			this->TableV2->AutoSize = true;
			this->TableV2->Location = System::Drawing::Point(11, 39);
			this->TableV2->Name = L"TableV2";
			this->TableV2->Size = System::Drawing::Size(77, 21);
			this->TableV2->TabIndex = 24;
			this->TableV2->TabStop = true;
			this->TableV2->Text = L"V2(x, y)";
			this->TableV2->UseVisualStyleBackColor = true;
			// 
			// TableV
			// 
			this->TableV->AutoSize = true;
			this->TableV->Checked = true;
			this->TableV->Location = System::Drawing::Point(11, 11);
			this->TableV->Name = L"TableV";
			this->TableV->Size = System::Drawing::Size(69, 21);
			this->TableV->TabIndex = 23;
			this->TableV->TabStop = true;
			this->TableV->Text = L"V(x, y)";
			this->TableV->UseVisualStyleBackColor = true;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->Grad);
			this->groupBox2->Controls->Add(this->MPIradio);
			this->groupBox2->Location = System::Drawing::Point(1105, 502);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(395, 95);
			this->groupBox2->TabIndex = 24;
			this->groupBox2->TabStop = false;
			// 
			// Grad
			// 
			this->Grad->AutoSize = true;
			this->Grad->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Grad->Location = System::Drawing::Point(0, 49);
			this->Grad->Name = L"Grad";
			this->Grad->Size = System::Drawing::Size(359, 29);
			this->Grad->TabIndex = 21;
			this->Grad->Text = L"Метод стохастического градиента";
			this->Grad->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(1170, 659);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(160, 47);
			this->button1->TabIndex = 25;
			this->button1->Text = L"Решение";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1585, 757);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->numericUpDownNiter);
			this->Controls->Add(this->numericUpDownEps);
			this->Controls->Add(this->numericUpDownM);
			this->Controls->Add(this->numericUpDownN);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownN))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownM))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownEps))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownNiter))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
};
}
