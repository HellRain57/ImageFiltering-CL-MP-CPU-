#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <math.h>
#include <msclr\marshal_cppstd.h>
#include <windows.h>
#include <winuser.h>
#include <omp.h>
#include <chrono>
#include <thread>
#include <list>
#include <iterator>
#include <bitset>
#include <CL/cl.h> 


#using <System.Windows.Forms.dll>
#using <system.windows.forms.dll>


using namespace System::Windows::Forms;
using namespace std;
using namespace chrono;



namespace Lab1 
{
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
	private: System::Windows::Forms::Button^ btnPicturePicker;
	private: System::Windows::Forms::GroupBox^ groupBoxMain;
	protected:

	protected:


	private: System::Windows::Forms::OpenFileDialog^ openFileDialogPicture;
	private: System::Windows::Forms::GroupBox^ groupBoxFilters;
	private: System::Windows::Forms::Button^ btnGreenFilter;
	private: System::Windows::Forms::Button^ btnBlueFilter;
	private: System::Windows::Forms::Button^ btnRedFilter;
	private: System::Windows::Forms::Button^ btnClarityFilter;
	private: System::Windows::Forms::Button^ btnSmoothingFilter;
	private: System::Windows::Forms::Button^ btnMedianFilter;
	private: System::Windows::Forms::GroupBox^ groupBoxStartImage;
	private: System::Windows::Forms::PictureBox^ pbStartImage;
	private: System::Windows::Forms::GroupBox^ groupBoxCPU;
	private: System::Windows::Forms::Label^ lblTimeCPU;




	private: System::Windows::Forms::PictureBox^ pbCPU;
	private: System::Windows::Forms::GroupBox^ groupBoxOpenMP;
	private: System::Windows::Forms::Label^ lblSpeedupOpenMP;


	private: System::Windows::Forms::Label^ lblTimeOpenMP;

	private: System::Windows::Forms::PictureBox^ pbOpenMP;
	private: System::Windows::Forms::GroupBox^ groupBoxOpenCL;
	private: System::Windows::Forms::Label^ lblSpeedupOpenCL;


	private: System::Windows::Forms::Label^ lblTimeOpenCL;

	private: System::Windows::Forms::PictureBox^ pbOpenCL;
	private: System::Windows::Forms::Button^ btnSaveCPU;
	private: System::Windows::Forms::Button^ btnSaveMP;
	private: System::Windows::Forms::Button^ btnSaveCL;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialogPicture;


	protected:


	private: System::ComponentModel::IContainer^ components;

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnPicturePicker = (gcnew System::Windows::Forms::Button());
			this->groupBoxMain = (gcnew System::Windows::Forms::GroupBox());
			this->groupBoxFilters = (gcnew System::Windows::Forms::GroupBox());
			this->btnGreenFilter = (gcnew System::Windows::Forms::Button());
			this->btnBlueFilter = (gcnew System::Windows::Forms::Button());
			this->btnRedFilter = (gcnew System::Windows::Forms::Button());
			this->btnClarityFilter = (gcnew System::Windows::Forms::Button());
			this->btnSmoothingFilter = (gcnew System::Windows::Forms::Button());
			this->btnMedianFilter = (gcnew System::Windows::Forms::Button());
			this->openFileDialogPicture = (gcnew System::Windows::Forms::OpenFileDialog());
			this->groupBoxStartImage = (gcnew System::Windows::Forms::GroupBox());
			this->pbStartImage = (gcnew System::Windows::Forms::PictureBox());
			this->groupBoxCPU = (gcnew System::Windows::Forms::GroupBox());
			this->lblTimeCPU = (gcnew System::Windows::Forms::Label());
			this->pbCPU = (gcnew System::Windows::Forms::PictureBox());
			this->groupBoxOpenMP = (gcnew System::Windows::Forms::GroupBox());
			this->lblSpeedupOpenMP = (gcnew System::Windows::Forms::Label());
			this->lblTimeOpenMP = (gcnew System::Windows::Forms::Label());
			this->pbOpenMP = (gcnew System::Windows::Forms::PictureBox());
			this->groupBoxOpenCL = (gcnew System::Windows::Forms::GroupBox());
			this->lblSpeedupOpenCL = (gcnew System::Windows::Forms::Label());
			this->lblTimeOpenCL = (gcnew System::Windows::Forms::Label());
			this->pbOpenCL = (gcnew System::Windows::Forms::PictureBox());
			this->btnSaveCPU = (gcnew System::Windows::Forms::Button());
			this->btnSaveMP = (gcnew System::Windows::Forms::Button());
			this->btnSaveCL = (gcnew System::Windows::Forms::Button());
			this->saveFileDialogPicture = (gcnew System::Windows::Forms::SaveFileDialog());
			this->groupBoxMain->SuspendLayout();
			this->groupBoxFilters->SuspendLayout();
			this->groupBoxStartImage->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbStartImage))->BeginInit();
			this->groupBoxCPU->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbCPU))->BeginInit();
			this->groupBoxOpenMP->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbOpenMP))->BeginInit();
			this->groupBoxOpenCL->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbOpenCL))->BeginInit();
			this->SuspendLayout();
			// 
			// btnPicturePicker
			// 
			this->btnPicturePicker->Location = System::Drawing::Point(149, 26);
			this->btnPicturePicker->Name = L"btnPicturePicker";
			this->btnPicturePicker->Size = System::Drawing::Size(136, 36);
			this->btnPicturePicker->TabIndex = 4;
			this->btnPicturePicker->Text = L"Открыть";
			this->btnPicturePicker->UseVisualStyleBackColor = true;
			this->btnPicturePicker->Click += gcnew System::EventHandler(this, &MyForm::btnPicturePicker_Click);
			// 
			// groupBoxMain
			// 
			this->groupBoxMain->Controls->Add(this->groupBoxFilters);
			this->groupBoxMain->Controls->Add(this->btnPicturePicker);
			this->groupBoxMain->Location = System::Drawing::Point(41, 47);
			this->groupBoxMain->Name = L"groupBoxMain";
			this->groupBoxMain->Size = System::Drawing::Size(449, 268);
			this->groupBoxMain->TabIndex = 8;
			this->groupBoxMain->TabStop = false;
			// 
			// groupBoxFilters
			// 
			this->groupBoxFilters->Controls->Add(this->btnGreenFilter);
			this->groupBoxFilters->Controls->Add(this->btnBlueFilter);
			this->groupBoxFilters->Controls->Add(this->btnRedFilter);
			this->groupBoxFilters->Controls->Add(this->btnClarityFilter);
			this->groupBoxFilters->Controls->Add(this->btnSmoothingFilter);
			this->groupBoxFilters->Controls->Add(this->btnMedianFilter);
			this->groupBoxFilters->Location = System::Drawing::Point(9, 68);
			this->groupBoxFilters->Name = L"groupBoxFilters";
			this->groupBoxFilters->Size = System::Drawing::Size(423, 193);
			this->groupBoxFilters->TabIndex = 20;
			this->groupBoxFilters->TabStop = false;
			this->groupBoxFilters->Visible = false;
			// 
			// btnGreenFilter
			// 
			this->btnGreenFilter->Location = System::Drawing::Point(229, 135);
			this->btnGreenFilter->Name = L"btnGreenFilter";
			this->btnGreenFilter->Size = System::Drawing::Size(162, 36);
			this->btnGreenFilter->TabIndex = 26;
			this->btnGreenFilter->Text = L"Фильтр зелёного цвета";
			this->btnGreenFilter->UseVisualStyleBackColor = true;
			this->btnGreenFilter->Click += gcnew System::EventHandler(this, &MyForm::btnGreenFilter_Click);
			// 
			// btnBlueFilter
			// 
			this->btnBlueFilter->Location = System::Drawing::Point(229, 84);
			this->btnBlueFilter->Name = L"btnBlueFilter";
			this->btnBlueFilter->Size = System::Drawing::Size(162, 36);
			this->btnBlueFilter->TabIndex = 25;
			this->btnBlueFilter->Text = L"Фильтр синего цвета";
			this->btnBlueFilter->UseVisualStyleBackColor = true;
			this->btnBlueFilter->Click += gcnew System::EventHandler(this, &MyForm::btnBlueFilter_Click);
			// 
			// btnRedFilter
			// 
			this->btnRedFilter->Location = System::Drawing::Point(229, 30);
			this->btnRedFilter->Name = L"btnRedFilter";
			this->btnRedFilter->Size = System::Drawing::Size(162, 36);
			this->btnRedFilter->TabIndex = 24;
			this->btnRedFilter->Text = L"Фильтр красного цвета";
			this->btnRedFilter->UseVisualStyleBackColor = true;
			this->btnRedFilter->Click += gcnew System::EventHandler(this, &MyForm::btnRedFilter_Click);
			// 
			// btnClarityFilter
			// 
			this->btnClarityFilter->Location = System::Drawing::Point(28, 84);
			this->btnClarityFilter->Name = L"btnClarityFilter";
			this->btnClarityFilter->Size = System::Drawing::Size(162, 36);
			this->btnClarityFilter->TabIndex = 22;
			this->btnClarityFilter->Text = L"Фильтр резкости";
			this->btnClarityFilter->UseVisualStyleBackColor = true;
			this->btnClarityFilter->Click += gcnew System::EventHandler(this, &MyForm::btnClarityFilter_Click);
			// 
			// btnSmoothingFilter
			// 
			this->btnSmoothingFilter->Location = System::Drawing::Point(28, 135);
			this->btnSmoothingFilter->Name = L"btnSmoothingFilter";
			this->btnSmoothingFilter->Size = System::Drawing::Size(162, 36);
			this->btnSmoothingFilter->TabIndex = 23;
			this->btnSmoothingFilter->Text = L"Фильтр сглаживания";
			this->btnSmoothingFilter->UseVisualStyleBackColor = true;
			this->btnSmoothingFilter->Click += gcnew System::EventHandler(this, &MyForm::btnSmoothingFilter_Click);
			// 
			// btnMedianFilter
			// 
			this->btnMedianFilter->Location = System::Drawing::Point(28, 30);
			this->btnMedianFilter->Name = L"btnMedianFilter";
			this->btnMedianFilter->Size = System::Drawing::Size(162, 36);
			this->btnMedianFilter->TabIndex = 21;
			this->btnMedianFilter->Text = L"Медианный фильтр";
			this->btnMedianFilter->UseVisualStyleBackColor = true;
			this->btnMedianFilter->Click += gcnew System::EventHandler(this, &MyForm::btnMedianFilter_Click);
			// 
			// openFileDialogPicture
			// 
			this->openFileDialogPicture->Filter = L"Images|*.bmp";
			// 
			// groupBoxStartImage
			// 
			this->groupBoxStartImage->BackColor = System::Drawing::Color::OldLace;
			this->groupBoxStartImage->Controls->Add(this->pbStartImage);
			this->groupBoxStartImage->Location = System::Drawing::Point(513, 12);
			this->groupBoxStartImage->Margin = System::Windows::Forms::Padding(2);
			this->groupBoxStartImage->Name = L"groupBoxStartImage";
			this->groupBoxStartImage->Padding = System::Windows::Forms::Padding(2);
			this->groupBoxStartImage->Size = System::Drawing::Size(323, 336);
			this->groupBoxStartImage->TabIndex = 17;
			this->groupBoxStartImage->TabStop = false;
			this->groupBoxStartImage->Text = L"До обработки";
			// 
			// pbStartImage
			// 
			this->pbStartImage->Location = System::Drawing::Point(4, 17);
			this->pbStartImage->Margin = System::Windows::Forms::Padding(2);
			this->pbStartImage->Name = L"pbStartImage";
			this->pbStartImage->Size = System::Drawing::Size(315, 315);
			this->pbStartImage->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pbStartImage->TabIndex = 1;
			this->pbStartImage->TabStop = false;
			// 
			// groupBoxCPU
			// 
			this->groupBoxCPU->BackColor = System::Drawing::Color::OldLace;
			this->groupBoxCPU->Controls->Add(this->lblTimeCPU);
			this->groupBoxCPU->Controls->Add(this->pbCPU);
			this->groupBoxCPU->Location = System::Drawing::Point(11, 362);
			this->groupBoxCPU->Margin = System::Windows::Forms::Padding(2);
			this->groupBoxCPU->Name = L"groupBoxCPU";
			this->groupBoxCPU->Padding = System::Windows::Forms::Padding(2);
			this->groupBoxCPU->Size = System::Drawing::Size(289, 375);
			this->groupBoxCPU->TabIndex = 18;
			this->groupBoxCPU->TabStop = false;
			this->groupBoxCPU->Text = L"После обработки (CPU)";
			// 
			// lblTimeCPU
			// 
			this->lblTimeCPU->AutoSize = true;
			this->lblTimeCPU->Location = System::Drawing::Point(27, 336);
			this->lblTimeCPU->Name = L"lblTimeCPU";
			this->lblTimeCPU->Size = System::Drawing::Size(43, 13);
			this->lblTimeCPU->TabIndex = 21;
			this->lblTimeCPU->Text = L"Время:";
			// 
			// pbCPU
			// 
			this->pbCPU->Location = System::Drawing::Point(4, 17);
			this->pbCPU->Margin = System::Windows::Forms::Padding(2);
			this->pbCPU->Name = L"pbCPU";
			this->pbCPU->Size = System::Drawing::Size(281, 298);
			this->pbCPU->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pbCPU->TabIndex = 1;
			this->pbCPU->TabStop = false;
			// 
			// groupBoxOpenMP
			// 
			this->groupBoxOpenMP->BackColor = System::Drawing::Color::OldLace;
			this->groupBoxOpenMP->Controls->Add(this->lblSpeedupOpenMP);
			this->groupBoxOpenMP->Controls->Add(this->lblTimeOpenMP);
			this->groupBoxOpenMP->Controls->Add(this->pbOpenMP);
			this->groupBoxOpenMP->Location = System::Drawing::Point(321, 362);
			this->groupBoxOpenMP->Margin = System::Windows::Forms::Padding(2);
			this->groupBoxOpenMP->Name = L"groupBoxOpenMP";
			this->groupBoxOpenMP->Padding = System::Windows::Forms::Padding(2);
			this->groupBoxOpenMP->Size = System::Drawing::Size(289, 375);
			this->groupBoxOpenMP->TabIndex = 19;
			this->groupBoxOpenMP->TabStop = false;
			this->groupBoxOpenMP->Text = L"После обработки (OpenMP)";
			// 
			// lblSpeedupOpenMP
			// 
			this->lblSpeedupOpenMP->AutoSize = true;
			this->lblSpeedupOpenMP->Location = System::Drawing::Point(8, 345);
			this->lblSpeedupOpenMP->Name = L"lblSpeedupOpenMP";
			this->lblSpeedupOpenMP->Size = System::Drawing::Size(66, 13);
			this->lblSpeedupOpenMP->TabIndex = 22;
			this->lblSpeedupOpenMP->Text = L"Ускорение:";
			// 
			// lblTimeOpenMP
			// 
			this->lblTimeOpenMP->AutoSize = true;
			this->lblTimeOpenMP->Location = System::Drawing::Point(8, 324);
			this->lblTimeOpenMP->Name = L"lblTimeOpenMP";
			this->lblTimeOpenMP->Size = System::Drawing::Size(43, 13);
			this->lblTimeOpenMP->TabIndex = 22;
			this->lblTimeOpenMP->Text = L"Время:";
			// 
			// pbOpenMP
			// 
			this->pbOpenMP->Location = System::Drawing::Point(4, 17);
			this->pbOpenMP->Margin = System::Windows::Forms::Padding(2);
			this->pbOpenMP->Name = L"pbOpenMP";
			this->pbOpenMP->Size = System::Drawing::Size(281, 298);
			this->pbOpenMP->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pbOpenMP->TabIndex = 1;
			this->pbOpenMP->TabStop = false;
			// 
			// groupBoxOpenCL
			// 
			this->groupBoxOpenCL->BackColor = System::Drawing::Color::OldLace;
			this->groupBoxOpenCL->Controls->Add(this->lblSpeedupOpenCL);
			this->groupBoxOpenCL->Controls->Add(this->lblTimeOpenCL);
			this->groupBoxOpenCL->Controls->Add(this->pbOpenCL);
			this->groupBoxOpenCL->Location = System::Drawing::Point(630, 362);
			this->groupBoxOpenCL->Margin = System::Windows::Forms::Padding(2);
			this->groupBoxOpenCL->Name = L"groupBoxOpenCL";
			this->groupBoxOpenCL->Padding = System::Windows::Forms::Padding(2);
			this->groupBoxOpenCL->Size = System::Drawing::Size(285, 375);
			this->groupBoxOpenCL->TabIndex = 6;
			this->groupBoxOpenCL->TabStop = false;
			this->groupBoxOpenCL->Text = L"После обработки (OpenCL)";
			// 
			// lblSpeedupOpenCL
			// 
			this->lblSpeedupOpenCL->AutoSize = true;
			this->lblSpeedupOpenCL->Location = System::Drawing::Point(8, 345);
			this->lblSpeedupOpenCL->Name = L"lblSpeedupOpenCL";
			this->lblSpeedupOpenCL->Size = System::Drawing::Size(66, 13);
			this->lblSpeedupOpenCL->TabIndex = 23;
			this->lblSpeedupOpenCL->Text = L"Ускорение:";
			// 
			// lblTimeOpenCL
			// 
			this->lblTimeOpenCL->AutoSize = true;
			this->lblTimeOpenCL->Location = System::Drawing::Point(8, 324);
			this->lblTimeOpenCL->Name = L"lblTimeOpenCL";
			this->lblTimeOpenCL->Size = System::Drawing::Size(43, 13);
			this->lblTimeOpenCL->TabIndex = 22;
			this->lblTimeOpenCL->Text = L"Время:";
			// 
			// pbOpenCL
			// 
			this->pbOpenCL->Location = System::Drawing::Point(4, 17);
			this->pbOpenCL->Margin = System::Windows::Forms::Padding(2);
			this->pbOpenCL->Name = L"pbOpenCL";
			this->pbOpenCL->Size = System::Drawing::Size(277, 298);
			this->pbOpenCL->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pbOpenCL->TabIndex = 1;
			this->pbOpenCL->TabStop = false;
			// 
			// btnSaveCPU
			// 
			this->btnSaveCPU->Enabled = false;
			this->btnSaveCPU->Location = System::Drawing::Point(11, 742);
			this->btnSaveCPU->Name = L"btnSaveCPU";
			this->btnSaveCPU->Size = System::Drawing::Size(289, 36);
			this->btnSaveCPU->TabIndex = 20;
			this->btnSaveCPU->Text = L"Сохранить";
			this->btnSaveCPU->UseVisualStyleBackColor = true;
			this->btnSaveCPU->Click += gcnew System::EventHandler(this, &MyForm::btnSaveCPU_Click);
			// 
			// btnSaveMP
			// 
			this->btnSaveMP->Enabled = false;
			this->btnSaveMP->Location = System::Drawing::Point(321, 742);
			this->btnSaveMP->Name = L"btnSaveMP";
			this->btnSaveMP->Size = System::Drawing::Size(289, 36);
			this->btnSaveMP->TabIndex = 21;
			this->btnSaveMP->Text = L"Сохранить";
			this->btnSaveMP->UseVisualStyleBackColor = true;
			this->btnSaveMP->Click += gcnew System::EventHandler(this, &MyForm::btnSaveMP_Click);
			// 
			// btnSaveCL
			// 
			this->btnSaveCL->Enabled = false;
			this->btnSaveCL->Location = System::Drawing::Point(630, 742);
			this->btnSaveCL->Name = L"btnSaveCL";
			this->btnSaveCL->Size = System::Drawing::Size(289, 36);
			this->btnSaveCL->TabIndex = 22;
			this->btnSaveCL->Text = L"Сохранить";
			this->btnSaveCL->UseVisualStyleBackColor = true;
			this->btnSaveCL->Click += gcnew System::EventHandler(this, &MyForm::btnSaveCL_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(926, 797);
			this->Controls->Add(this->btnSaveCL);
			this->Controls->Add(this->btnSaveMP);
			this->Controls->Add(this->btnSaveCPU);
			this->Controls->Add(this->groupBoxOpenCL);
			this->Controls->Add(this->groupBoxOpenMP);
			this->Controls->Add(this->groupBoxCPU);
			this->Controls->Add(this->groupBoxStartImage);
			this->Controls->Add(this->groupBoxMain);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->KeyPreview = true;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"Фильтрация изображений";
			this->Shown += gcnew System::EventHandler(this, &MyForm::MyForm_Shown);
			this->groupBoxMain->ResumeLayout(false);
			this->groupBoxFilters->ResumeLayout(false);
			this->groupBoxStartImage->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbStartImage))->EndInit();
			this->groupBoxCPU->ResumeLayout(false);
			this->groupBoxCPU->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbCPU))->EndInit();
			this->groupBoxOpenMP->ResumeLayout(false);
			this->groupBoxOpenMP->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbOpenMP))->EndInit();
			this->groupBoxOpenCL->ResumeLayout(false);
			this->groupBoxOpenCL->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbOpenCL))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion


	private: cl_device_id* devices; //Список OpenCL устройств
	private: int imageWidth, imageHeight; //Ширина и высота изображения
	private: byte *imageR, *imageG, *imageB; //Массивы компонент R,G и B для каждого пикселя 
	private: long size; //Размер изображения, вычилсяется как произведение ширины на высоту
	private: int timeCPU = 1; //Время выполнения на CPU, чтобы считать ускорение


	private: System::Void btnPicturePicker_Click(System::Object^ sender, System::EventArgs^ e) {
		openFileDialogPicture->Title = "Select picture ";
		openFileDialogPicture->Multiselect = false;
		if (openFileDialogPicture->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			String^ FileName = openFileDialogPicture->FileName->ToString();
			pbStartImage->Image = Image::FromFile(FileName);

			imageWidth = pbStartImage->Image->Width;
			imageHeight = pbStartImage->Image->Height;
			size = imageWidth * imageHeight;
			GetColorArrays();
			groupBoxFilters->Visible = true;
		}
		pbStartImage->Refresh();
		this->Refresh();
	}

	/// <summary>
	/// Метод, который заполняет массивы компонент для R, G и B
	/// </summary>
	private: void GetColorArrays()
	{
		Bitmap^ bmpImage = gcnew Bitmap(pbStartImage->Image);
		imageR = new byte[size];
		imageG = new byte[size];
		imageB = new byte[size];

		for (int i = 0; i < imageWidth; i++)
		{
			for (int j = 0; j < imageHeight; j++)
			{
				Color pixel = bmpImage->GetPixel(i, j);
				imageR[i * imageHeight + j] = pixel.R;
				imageG[i * imageHeight + j] = pixel.G;
				imageB[i * imageHeight + j] = pixel.B;
			}
		}
	}

	/// <summary>
	/// Метод, который из массивов цветовых компонента сделает Bitmap изображение
	/// </summary>
	private: Bitmap^ GetBitmapFromArrays(byte* imageArrayR, byte *imageArrayG, byte *imageArrayB)
	{
		Bitmap^ bmpResultImage = gcnew Bitmap(imageWidth, imageHeight);
		for (int i = 0; i < imageWidth; i++) {
			for (int j = 0; j < imageHeight; j++) {
				Color pixel = Color::FromArgb(imageArrayR[i * imageHeight + j], imageArrayG[i * imageHeight + j], imageArrayB[i * imageHeight + j]);
				bmpResultImage->SetPixel(i, j, pixel);
			}
		}
		return bmpResultImage;
	}


	/// <summary>
	/// Метод, который вернёт строку с удобным видом времени выполнения
	/// </summary>
	private: String^ GetNormalTime(int time)
	{
		if (time >= 1000) return "Время: " + (time / 1000) + "," + (time % 1000) + " мс";
		return "Время: 0," + time + " мс";
	}


	/// <summary>
	/// Устанавливает доступность кнопок сохранения для изображений
	/// </summary>
	private: void SetBtnSaveEnabled(bool state)
	{
		btnSaveCL->Enabled = state;
		btnSaveMP->Enabled = state;
		btnSaveCPU->Enabled = state;
	}


	private: System::Void btnMedianFilter_Click(System::Object^ sender, System::EventArgs^ e) {
		MedianFilterCPU();
		MedianFilterOpenMP();
		FilterOpenCL("medianFilter", imageWidth - 2, imageHeight - 2);
		SetBtnSaveEnabled(true);
	}

	/// <summary>
	/// Запускает медианный фильтр на CPU
	/// </summary>
	private: void MedianFilterCPU()
	{
		// Переменные для замера времени и цветовых компонент
		high_resolution_clock::time_point startTime, finishTime;
		byte* imageRCPU = new byte[size];
		byte* imageGCPU = new byte[size];
		byte* imageBCPU = new byte[size];

		startTime = high_resolution_clock::now();
		for (int a = 1; a < imageWidth-1; a++)
		{
			for (int b = 1; b < imageHeight-1; b++)
			{
				// Заполнение промежуточных массивов по ядру свёртки
				float tempR[9], tempG[9], tempB[9];
				for (int i = -1; i < 2; i++)
				{
					for (int j = -1; j < 2; j++)
					{
						tempR[(i + 1) * 3 + j + 1] = imageR[a * imageHeight + b + i * imageHeight + j];
						tempG[(i + 1) * 3 + j + 1] = imageG[a * imageHeight + b + i * imageHeight + j];
						tempB[(i + 1) * 3 + j + 1] = imageB[a * imageHeight + b + i * imageHeight + j];
					}
				}

				// Пузырьковая сортировка массивов цветовых компонент
				for (int i = 0; i < 5; i++) {
					for (int j = 0; j < (8 - i); j++) {
						if ((tempR[j] > tempR[j + 1])) {

							float copy = tempR[j];
							tempR[j] = tempR[j + 1];
							tempR[j + 1] = copy;
						}

						if ((tempG[j] > tempG[j + 1])) {

							float copy = tempG[j];
							tempG[j] = tempG[j + 1];
							tempG[j + 1] = copy;
						}

						if ((tempB[j] > tempB[j + 1])) {

							float copy = tempB[j];
							tempB[j] = tempB[j + 1];
							tempB[j + 1] = copy;
						}
					}
				}

				// Запись результатов в выходное изображение
				imageRCPU[a * imageHeight + b] = tempR[4];
				imageGCPU[a * imageHeight + b] = tempG[4];
				imageBCPU[a * imageHeight + b] = tempB[4];
			}
		}
		finishTime = high_resolution_clock::now();

		// Вывод результатов выполнения алгоритма
		timeCPU = std::chrono::duration_cast<std::chrono::microseconds>(finishTime - startTime).count();
		lblTimeCPU->Text = GetNormalTime(timeCPU);
		pbCPU->Image = GetBitmapFromArrays(imageRCPU, imageGCPU, imageBCPU);
	}

	/// <summary>
	/// Запускает медианный фильтр на OpenMP
	/// </summary>
	private: void MedianFilterOpenMP()
	{
		// Переменные для замера времени и цветовых компонент
		high_resolution_clock::time_point startTime, finishTime;
		byte* imageR_MP = new byte[size];
		byte* imageG_MP = new byte[size];
		byte* imageB_MP = new byte[size];

		startTime = high_resolution_clock::now();
		for (int a = 1; a < imageWidth - 1; a++)
		{
			// Создание параллельной области, которая будет перебирать элементы в рамках одной строки
			#pragma omp parallel firstprivate(a)
			{
				// Идентификатор потока будет выступать как указатель на конкретный элемент в рамках строки
				int id = omp_get_thread_num();

				// Пока указатель на столбец меньше количества столбцов
				while (id < imageHeight - 1)
				{
					// Заполнение промежуточных массивов по ядру свёртки
					float tempR[9], tempG[9], tempB[9];
					for (int i = -1; i < 2; i++)
					{
						for (int j = -1; j < 2; j++)
						{
							tempR[(i + 1) * 3 + j + 1] = imageR[a * imageHeight + id + i * imageHeight + j];
							tempG[(i + 1) * 3 + j + 1] = imageG[a * imageHeight + id + i * imageHeight + j];
							tempB[(i + 1) * 3 + j + 1] = imageB[a * imageHeight + id + i * imageHeight + j];
						}
					}

					// Пузырьковая сортировка массивов цветовых компонент
					for (int i = 0; i < 5; i++) {
						for (int j = 0; j < (8 - i); j++) {
							if ((tempR[j] > tempR[j + 1])) {

								float copy = tempR[j];
								tempR[j] = tempR[j + 1];
								tempR[j + 1] = copy;
							}

							if ((tempG[j] > tempG[j + 1])) {

								float copy = tempG[j];
								tempG[j] = tempG[j + 1];
								tempG[j + 1] = copy;
							}

							if ((tempB[j] > tempB[j + 1])) {

								float copy = tempB[j];
								tempB[j] = tempB[j + 1];
								tempB[j + 1] = copy;
							}
						}
					}

					// Запись результатов в выходное изображение
					imageR_MP[a * imageHeight + id] = tempR[4];
					imageG_MP[a * imageHeight + id] = tempG[4];
					imageB_MP[a * imageHeight + id] = tempB[4];

					// Увеличиваем указатель на максимальное число потоков
					id += omp_get_num_threads();
				}
			}
		}
		finishTime = high_resolution_clock::now();

		// Вывод результатов выполнения алгоритма
		int time = std::chrono::duration_cast<std::chrono::microseconds>(finishTime - startTime).count();
		lblTimeOpenMP->Text = GetNormalTime(time);
		double speedup = (1.0) * timeCPU / time;
		lblSpeedupOpenMP->Text = "Ускорение: " + Math::Round(speedup, 3);

		pbOpenMP->Image = GetBitmapFromArrays(imageR_MP, imageG_MP, imageB_MP);
	}





	private: System::Void btnClarityFilter_Click(System::Object^ sender, System::EventArgs^ e) {
		ClarityFilterCPU();
		ClarityFilterOpenMP();
		FilterOpenCL("clarityFilter", imageWidth - 2, imageHeight - 2);
		SetBtnSaveEnabled(true);
	}

	/// <summary>
	/// Запускает фильтр резкости на CPU
	/// </summary>
	private: void ClarityFilterCPU()
	{
		// Переменные для замера времени и цветовых компонент
		high_resolution_clock::time_point startTime, finishTime;
		byte* imageRCPU = new byte[size];
		byte* imageGCPU = new byte[size];
		byte* imageBCPU = new byte[size];

		startTime = high_resolution_clock::now();
		for (int a = 1; a < imageWidth - 1; a++)
		{
			for (int b = 1; b < imageHeight - 1; b++)
			{
				// Заполнение промежуточных массивов по ядру свёртки
				float tempR[9], tempG[9], tempB[9];
				for (int i = -1; i < 2; i++)
				{
					for (int j = -1; j < 2; j++)
					{
						tempR[(i + 1) * 3 + j + 1] = imageR[a * imageHeight + b + i * imageHeight + j];
						tempG[(i + 1) * 3 + j + 1] = imageG[a * imageHeight + b + i * imageHeight + j];
						tempB[(i + 1) * 3 + j + 1] = imageB[a * imageHeight + b + i * imageHeight + j];
					}
				}

				// Считается сумма по цветам умноженным на значения ядра свёртки
				int tempValueR = (-1) * tempR[0];
				int tempValueG = (-1) * tempG[0];
				int tempValueB = (-1) * tempB[0];
				for (int i = 1; i < 9; i++) {
					if (i == 4)
					{
						tempValueR += 9 * tempR[4];
						tempValueG += 9 * tempG[4];
						tempValueB += 9 * tempB[4];
					}
					else
					{
						tempValueR += (-1) * tempR[i];
						tempValueG += (-1) * tempG[i];
						tempValueB += (-1) * tempB[i];
					}
				}

				// Запись результатов в выходное изображение
				imageRCPU[a * imageHeight + b] = (tempValueR < 0) ? 0 : (tempValueR > 255) ? 255 : tempValueR;
				imageGCPU[a * imageHeight + b] = (tempValueG < 0) ? 0 : (tempValueG > 255) ? 255 : tempValueG;
				imageBCPU[a * imageHeight + b] = (tempValueB < 0) ? 0 : (tempValueB > 255) ? 255 : tempValueB;
			}
		}
		finishTime = high_resolution_clock::now();

		// Вывод результатов выполнения алгоритма
		timeCPU = std::chrono::duration_cast<std::chrono::microseconds>(finishTime - startTime).count();
		lblTimeCPU->Text = GetNormalTime(timeCPU);
		pbCPU->Image = GetBitmapFromArrays(imageRCPU, imageGCPU, imageBCPU);
	}

	/// <summary>
	///  Запускает фильтр резкости на OpenMP
	/// </summary>
	private: void ClarityFilterOpenMP()
	{
		// Переменные для замера времени и цветовых компонент
		high_resolution_clock::time_point startTime, finishTime;
		byte* imageR_MP = new byte[size];
		byte* imageG_MP = new byte[size];
		byte* imageB_MP = new byte[size];

		startTime = high_resolution_clock::now();
		for (int a = 1; a < imageWidth - 1; a++)
		{
			// Создание параллельной области для просмотра элементов в строке
			#pragma omp parallel firstprivate(a)
			{
				// Идентификатор потока будет выступать как указатель на конкретный элемент в рамках строки
				int id = omp_get_thread_num();

				// Пока указатель на столбец меньше количества столбцов
				while (id < imageHeight - 1)
				{
					// Заполнение промежуточных массивов по ядру свёртки
					float tempR[9], tempG[9], tempB[9];
					for (int i = -1; i < 2; i++)
					{
						for (int j = -1; j < 2; j++)
						{
							tempR[(i + 1) * 3 + j + 1] = imageR[a * imageHeight + id + i * imageHeight + j];
							tempG[(i + 1) * 3 + j + 1] = imageG[a * imageHeight + id + i * imageHeight + j];
							tempB[(i + 1) * 3 + j + 1] = imageB[a * imageHeight + id + i * imageHeight + j];
						}
					}

					// Считается сумма по цветам умноженным на значения ядра свёртки
					int tempValueR = (-1) * tempR[0];
					int tempValueG = (-1) * tempG[0];
					int tempValueB = (-1) * tempB[0];
					for (int i = 1; i < 9; i++) {
						if (i == 4)
						{
							tempValueR += 9 * tempR[4];
							tempValueG += 9 * tempG[4];
							tempValueB += 9 * tempB[4];
						}
						else
						{
							tempValueR += (-1) * tempR[i];
							tempValueG += (-1) * tempG[i];
							tempValueB += (-1) * tempB[i];
						}
					}

					// Запись результатов в выходное изображение
					imageR_MP[a * imageHeight + id] = (tempValueR < 0) ? 0 : (tempValueR > 255) ? 255 : tempValueR;
					imageG_MP[a * imageHeight + id] = (tempValueG < 0) ? 0 : (tempValueG > 255) ? 255 : tempValueG;
					imageB_MP[a * imageHeight + id] = (tempValueB < 0) ? 0 : (tempValueB > 255) ? 255 : tempValueB;

					// Увеличиваем указатель на максимальное число потоков
					id += omp_get_num_threads();
				}
			}
		}
		finishTime = high_resolution_clock::now();

		// Вывод результатов выполнения алгоритма
		int time = std::chrono::duration_cast<std::chrono::microseconds>(finishTime - startTime).count();
		lblTimeOpenMP->Text = GetNormalTime(time);
		double speedup = (1.0) * timeCPU / time;
		lblSpeedupOpenMP->Text = "Ускорение: " + Math::Round(speedup, 3);
		pbOpenMP->Image = GetBitmapFromArrays(imageR_MP, imageG_MP, imageB_MP);
	}




	private: System::Void btnSmoothingFilter_Click(System::Object^ sender, System::EventArgs^ e) {
		SmoothingFilterCPU();
		SmoothingFilterOpenMP();
		FilterOpenCL("smoothingFilter", imageWidth-2, imageHeight-2);
		SetBtnSaveEnabled(true);
	}

	/// <summary>
	/// Запускает фильтр сглаживания на CPU
	/// </summary>
	private: void SmoothingFilterCPU()
	{
		// Переменные для замера времени и цветовых компонент
		high_resolution_clock::time_point startTime, finishTime;
		byte* imageRCPU = new byte[size];
		byte* imageGCPU = new byte[size];
		byte* imageBCPU = new byte[size];

		startTime = high_resolution_clock::now();
		for (int a = 1; a < imageWidth - 1; a++)
		{
			for (int b = 1; b < imageHeight - 1; b++)
			{
				// Заполнение промежуточных массивов по ядру свёртки
				float tempR[9], tempG[9], tempB[9];
				for (int i = -1; i < 2; i++)
				{
					for (int j = -1; j < 2; j++)
					{
						tempR[(i + 1) * 3 + j + 1] = imageR[a * imageHeight + b + i * imageHeight + j];
						tempG[(i + 1) * 3 + j + 1] = imageG[a * imageHeight + b + i * imageHeight + j];
						tempB[(i + 1) * 3 + j + 1] = imageB[a * imageHeight + b + i * imageHeight + j];
					}
				}

				// Считается сумма по цветам умноженным на значения ядра свёртки
				int tempValueR = tempR[0];
				int tempValueG = tempG[0];
				int tempValueB = tempB[0];
				for (int i = 1; i < 9; i++) {
					tempValueR += tempR[i];
					tempValueG += tempG[i];
					tempValueB += tempB[i];
				}
				tempValueR = tempValueR / 9;
				tempValueG = tempValueG / 9;
				tempValueB = tempValueB / 9;

				// Запись результатов в выходное изображение
				imageRCPU[a * imageHeight + b] = (tempValueR < 0) ? 0 : (tempValueR > 255) ? 255 : tempValueR;
				imageGCPU[a * imageHeight + b] = (tempValueG < 0) ? 0 : (tempValueG > 255) ? 255 : tempValueG;
				imageBCPU[a * imageHeight + b] = (tempValueB < 0) ? 0 : (tempValueB > 255) ? 255 : tempValueB;
			}
		}
		finishTime = high_resolution_clock::now();

		// Вывод результатов выполнения алгоритма
		timeCPU = std::chrono::duration_cast<std::chrono::microseconds>(finishTime - startTime).count();
		lblTimeCPU->Text = GetNormalTime(timeCPU);
		pbCPU->Image = GetBitmapFromArrays(imageRCPU, imageGCPU, imageBCPU);
	}


	/// <summary>
	/// Запускает фильтр сглаживания на OpenMP
	/// </summary>
	private: void SmoothingFilterOpenMP()
	{
		// Переменные для замера времени и цветовых компонент
		high_resolution_clock::time_point startTime, finishTime;
		byte* imageR_MP = new byte[size];
		byte* imageG_MP = new byte[size];
		byte* imageB_MP = new byte[size];

		startTime = high_resolution_clock::now();
		for (int a = 1; a < imageWidth - 1; a++)
		{
			#pragma omp parallel firstprivate(a)
			{
				// Идентификатор потока будет выступать как указатель на конкретный элемент в рамках строки
				int id = omp_get_thread_num();

				// Пока указатель на столбец меньше количества столбцов
				while (id < imageHeight - 1)
				{
					// Заполнение промежуточных массивов по ядру свёртки
					float tempR[9], tempG[9], tempB[9];
					for (int i = -1; i < 2; i++)
					{
						for (int j = -1; j < 2; j++)
						{
							tempR[(i + 1) * 3 + j + 1] = imageR[a * imageHeight + id + i * imageHeight + j];
							tempG[(i + 1) * 3 + j + 1] = imageG[a * imageHeight + id + i * imageHeight + j];
							tempB[(i + 1) * 3 + j + 1] = imageB[a * imageHeight + id + i * imageHeight + j];
						}
					}

					// Считается сумма по цветам умноженным на значения ядра свёртки
					int tempValueR = tempR[0];
					int tempValueG = tempG[0];
					int tempValueB = tempB[0];
					for (int i = 1; i < 9; i++) {
						tempValueR += tempR[i];
						tempValueG += tempG[i];
						tempValueB += tempB[i];
					}
					tempValueR = tempValueR / 9;
					tempValueG = tempValueG / 9;
					tempValueB = tempValueB / 9;

					// Запись результатов в выходное изображение
					imageR_MP[a * imageHeight + id] = (tempValueR < 0) ? 0 : (tempValueR > 255) ? 255 : tempValueR;
					imageG_MP[a * imageHeight + id] = (tempValueG < 0) ? 0 : (tempValueG > 255) ? 255 : tempValueG;
					imageB_MP[a * imageHeight + id] = (tempValueB < 0) ? 0 : (tempValueB > 255) ? 255 : tempValueB;
					
					// Увеличиваем указатель на максимальное число потоков
					id += omp_get_num_threads();
				}
			}
		}
		finishTime = high_resolution_clock::now();

		// Вывод результатов выполнения алгоритма
		int time = std::chrono::duration_cast<std::chrono::microseconds>(finishTime - startTime).count();
		lblTimeOpenMP->Text = GetNormalTime(time);
		double speedup = (1.0) * timeCPU / time;
		lblSpeedupOpenMP->Text = "Ускорение: " + Math::Round(speedup, 3);
		pbOpenMP->Image = GetBitmapFromArrays(imageR_MP, imageG_MP, imageB_MP);
	}




	private: System::Void btnRedFilter_Click(System::Object^ sender, System::EventArgs^ e) {
		RedFilterCPU();
		RedFilterOpenMP();
		FilterOpenCL("redFilter", imageWidth, imageHeight);
		SetBtnSaveEnabled(true);
	}

	/// <summary>
	/// Запускает фильтр красного цвета на CPU
	/// </summary>
	private: void RedFilterCPU()
	{
		// Переменные для замера времени и выходного Bitmap изображения
		high_resolution_clock::time_point startTime, finishTime;
		Bitmap^ bmpResultImage = gcnew Bitmap(imageWidth, imageHeight);

		startTime = high_resolution_clock::now();
		for (int i = 0; i < imageWidth; i++) {
			for (int j = 0; j < imageHeight; j++) {
				Color pixel = Color::FromArgb(imageR[i * imageHeight + j], 0, 0); // Заполняем компоненту красного цвета из исходного изображения, а остальные 0
				bmpResultImage->SetPixel(i, j, pixel);
			}
		}
		finishTime = high_resolution_clock::now();

		// Вывод результатов выполнения алгоритма
		timeCPU = std::chrono::duration_cast<std::chrono::microseconds>(finishTime - startTime).count();
		lblTimeCPU->Text = GetNormalTime(timeCPU);
		pbCPU->Image = bmpResultImage;
	}

	/// <summary>
	///  Запускает фильтр красного цвета на OpenMP
	/// </summary>
	private: void RedFilterOpenMP()
	{
		// Переменные для замера времени и выходного Bitmap изображения
		high_resolution_clock::time_point startTime, finishTime;
		Bitmap^ bmpResultImage = gcnew Bitmap(imageWidth, imageHeight);

		startTime = high_resolution_clock::now();
		for (int i = 0; i < imageWidth; i++) {
			// Создание параллельной области
			#pragma omp parallel firstprivate(i)
			{
				// Указатель на элемент в строке
				int id = omp_get_thread_num();

				// Пока указатель меньше количества столбцов
				while (id < imageHeight)
				{
					Color pixel = Color::FromArgb(imageR[i * imageHeight + id], 0, 0); // Заполняем компоненту красного цвета из исходного изображения, а остальные 0

					// Создаём критическую секцию, в которую может зайти только один поток
					#pragma omp critical
					{
						bmpResultImage->SetPixel(i, id, pixel);
					}

					// Увеличить указатель на максимальное число потоков
					id += omp_get_num_threads();
				}
			}
		}
		finishTime = high_resolution_clock::now();

		// Вывод результатов выполнения алгоритма
		int time = std::chrono::duration_cast<std::chrono::microseconds>(finishTime - startTime).count();
		lblTimeOpenMP->Text = GetNormalTime(time);
		double speedup = (1.0) * timeCPU / time;
		lblSpeedupOpenMP->Text = "Ускорение: " + Math::Round(speedup, 3);
		pbOpenMP->Image = bmpResultImage;
	}





	private: System::Void btnBlueFilter_Click(System::Object^ sender, System::EventArgs^ e) {
		BlueFilterCPU();
		BlueFilterOpenMP();
		FilterOpenCL("blueFilter", imageWidth, imageHeight);
		SetBtnSaveEnabled(true);
	}

	/// <summary>
	/// Запускает фильтр синего цвета на CPU
	/// </summary>
	private: void BlueFilterCPU()
	{
		// Переменные для замера времени и выходного Bitmap изображения
		high_resolution_clock::time_point startTime, finishTime;
		Bitmap^ bmpResultImage = gcnew Bitmap(imageWidth, imageHeight);

		startTime = high_resolution_clock::now();
		for (int i = 0; i < imageWidth; i++) {
			for (int j = 0; j < imageHeight; j++) {
				Color pixel = Color::FromArgb(0, 0, imageB[i * imageHeight + j]); // Заполняем компоненту синего цвета из исходного изображения, а остальные 0
				bmpResultImage->SetPixel(i, j, pixel);
			}
		}
		finishTime = high_resolution_clock::now();

		// Вывод результатов выполнения алгоритма
		timeCPU = std::chrono::duration_cast<std::chrono::microseconds>(finishTime - startTime).count();
		lblTimeCPU->Text = GetNormalTime(timeCPU);
		pbCPU->Image = bmpResultImage;
	}

	/// <summary>
	/// Запускает фильтр синего цвета на OpenMP
	/// </summary>
	private: void BlueFilterOpenMP()
	{
		// Переменные для замера времени и выходного Bitmap изображения
		high_resolution_clock::time_point startTime, finishTime;
		Bitmap^ bmpResultImage = gcnew Bitmap(imageWidth, imageHeight);

		startTime = high_resolution_clock::now();
		for (int i = 0; i < imageWidth; i++) {
			// Создание параллельной области
			#pragma omp parallel firstprivate(i)
			{
				// Указатель на элемент в строке
				int id = omp_get_thread_num();

				// Пока указатель меньше количества столбцов
				while (id < imageHeight)
				{
					Color pixel = Color::FromArgb(0, 0, imageB[i * imageHeight + id]);  // Заполняем компоненту синего цвета из исходного изображения, а остальные 0

					// Создаём критическую секцию, в которую может зайти только один поток					
					#pragma omp critical
					{
						bmpResultImage->SetPixel(i, id, pixel);
					}

					// Увеличить указатель на максимальное число потоков
					id += omp_get_num_threads();
				}
			}
		}
		finishTime = high_resolution_clock::now();

		// Вывод результатов выполнения алгоритма
		int time = std::chrono::duration_cast<std::chrono::microseconds>(finishTime - startTime).count();
		lblTimeOpenMP->Text = GetNormalTime(time);
		double speedup = (1.0) * timeCPU / time;
		lblSpeedupOpenMP->Text = "Ускорение: " + Math::Round(speedup, 3);
		pbOpenMP->Image = bmpResultImage;
	}




	private: System::Void btnGreenFilter_Click(System::Object^ sender, System::EventArgs^ e) {
		GreenFilterCPU();
		GreenFilterOpenMP();
		FilterOpenCL("greenFilter", imageWidth, imageHeight);
		SetBtnSaveEnabled(true);
	}

	/// <summary>
	/// Запускает фильтр зелёного цвета на CPU
	/// </summary>
	private: void GreenFilterCPU()
	{
		// Переменные для замера времени и выходного Bitmap изображения
		high_resolution_clock::time_point startTime, finishTime;
		Bitmap^ bmpResultImage = gcnew Bitmap(imageWidth, imageHeight);

		startTime = high_resolution_clock::now();
		for (int i = 0; i < imageWidth; i++) {
			for (int j = 0; j < imageHeight; j++) {
				Color pixel = Color::FromArgb(0, imageG[i * imageHeight + j], 0); // Заполняем компоненту зелёного цвета из исходного изображения, а остальные 0
				bmpResultImage->SetPixel(i, j, pixel);
			}
		}
		finishTime = high_resolution_clock::now();

		// Вывод результатов выполнения алгоритма
		timeCPU = std::chrono::duration_cast<std::chrono::microseconds>(finishTime - startTime).count();
		lblTimeCPU->Text = GetNormalTime(timeCPU);
		pbCPU->Image = bmpResultImage;
	}

	/// <summary>
	/// Запускает фильтр зелёного цвета на OpenMP
	/// </summary>
	private: void GreenFilterOpenMP()
	{
		// Переменные для замера времени и выходного Bitmap изображения
		high_resolution_clock::time_point startTime, finishTime;
		Bitmap^ bmpResultImage = gcnew Bitmap(imageWidth, imageHeight);

		startTime = high_resolution_clock::now();
		for (int i = 0; i < imageWidth; i++) {
			// Создание параллельной области
			#pragma omp parallel firstprivate(i)
			{
				// Указатель на элемент в строке
				int id = omp_get_thread_num();

				// Пока указатель меньше количества столбцов
				while (id < imageHeight)
				{
					Color pixel = Color::FromArgb(0, imageG[i * imageHeight + id], 0); // Заполняем компоненту зелёного цвета из исходного изображения, а остальные 0

					// Создаём критическую секцию, в которую может зайти только один поток	
					#pragma omp critical
					{
						bmpResultImage->SetPixel(i, id, pixel);
					}

					// Увеличить указатель на максимальное число потоков
					id += omp_get_num_threads();
				}
			}
		}
		finishTime = high_resolution_clock::now();

		// Вывод результатов выполнения алгоритма
		int time = std::chrono::duration_cast<std::chrono::microseconds>(finishTime - startTime).count();
		lblTimeOpenMP->Text = GetNormalTime(time);
		double speedup = (1.0) * timeCPU / time;
		lblSpeedupOpenMP->Text = "Ускорение: " + Math::Round(speedup, 3);
		pbOpenMP->Image = bmpResultImage;
	}



	/// <summary>
	/// Запускает фильтры на OpenCL, в качестве параметра принимает имя фильтра и размеры рабочей области
	/// </summary>
	private: void FilterOpenCL(const char* kernelName, int width, int height)
	{
		// Переменные для замера времени
		high_resolution_clock::time_point startTime, finishTime;

		// Создание программы для OpenCL из специального файла
		cl_int status = 0;
		cl_context context = clCreateContext(NULL, 1, devices, NULL, NULL, NULL);
		cl_command_queue commandQueue = clCreateCommandQueue(context, devices[0], 0, NULL);

		const char* fileName = "filters.cl";
		std::string sourceCode;
		status = convertToString(fileName, sourceCode);
		const char* source = sourceCode.c_str();
		size_t sizeOfSource[] = { strlen(source) };
		cl_program program = clCreateProgramWithSource(context, 1, &source, sizeOfSource, &status);
		status = clBuildProgram(program, 1, devices, NULL, NULL, NULL);


		// Вывод лога об ошибке
		if (status == CL_BUILD_PROGRAM_FAILURE) {
			// Determine the size of the log
			size_t log_size;
			clGetProgramBuildInfo(program, devices[0], CL_PROGRAM_BUILD_LOG, 0, NULL, &log_size);

			// Allocate memory for the log
			char* log = (char*)malloc(log_size);

			// Get the log
			clGetProgramBuildInfo(program, devices[0], CL_PROGRAM_BUILD_LOG, log_size, log, NULL);

			// Print the log
			msclr::interop::marshal_context context2;
			String^ log_string = context2.marshal_as<String^>(string(log));
			std::string name = kernelName;
			String^ errorName = context2.marshal_as<String^>(string(name));
			System::Windows::Forms::MessageBox::Show(log_string, errorName + " - Error", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
		}

		// Заполнение массива для входного изображения
		cl_image_format* imageFormat = new cl_image_format;
		imageFormat->image_channel_order = CL_ARGB;
		imageFormat->image_channel_data_type = CL_UNSIGNED_INT8;
		size_t imageWidth = pbStartImage->Image->Width;
		size_t imageHeight = pbStartImage->Image->Height;
		Bitmap^ bmpInputImage = gcnew Bitmap(pbStartImage->Image);
		unsigned char* inputImagePixels = new unsigned char[imageHeight * imageWidth * 4];
		unsigned char* ch = &inputImagePixels[0];
		for (int i = 0; i < imageHeight; i++)
		{
			for (int j = 0; j < imageWidth; j++)
			{
				*ch++ = bmpInputImage->GetPixel(j, i).A;
				*ch++ = bmpInputImage->GetPixel(j, i).R;
				*ch++ = bmpInputImage->GetPixel(j, i).G;
				*ch++ = bmpInputImage->GetPixel(j, i).B;
			}
		}

		// Загрузка параметров входного и выходного изображений на OpenCL устройство
		cl_mem inputImage2DBuffer = clCreateImage2D(context, CL_MEM_COPY_HOST_PTR | CL_MEM_READ_ONLY, imageFormat, imageWidth, imageHeight, 0, (void*)inputImagePixels, &status);
		cl_mem outputImage2DBuffer = clCreateImage2D(context, CL_MEM_WRITE_ONLY, imageFormat, imageWidth, imageHeight, 0, NULL, &status);
		cl_kernel kernel = clCreateKernel(program, kernelName, &status);
		status = clSetKernelArg(kernel, 0, sizeof(cl_mem), (void*)&inputImage2DBuffer);
		status = clSetKernelArg(kernel, 1, sizeof(cl_mem), (void*)&outputImage2DBuffer);
		size_t global_work_size[] = { width, height }; // Определение размеров рабочей области

		startTime = high_resolution_clock::now();
		status = clEnqueueNDRangeKernel(commandQueue, kernel, 2, NULL, global_work_size, NULL, 0, NULL, NULL); // Выполнение алгоритма на OpenCL
		finishTime = high_resolution_clock::now();
		int time = std::chrono::duration_cast<std::chrono::microseconds>(finishTime - startTime).count();
		lblTimeOpenCL->Text = GetNormalTime(time);
		double speedup = (1.0) * timeCPU / time;
		lblSpeedupOpenCL->Text = "Ускорение: " + Math::Round(speedup, 3);

		// Чтение результата после выполнения алгоритма на OpenCL
		size_t origin[3] = { 0, 0, 0 };
		size_t region[3] = { imageWidth, imageHeight, 1 };
		unsigned char* outputImagePixels = new unsigned char[imageWidth * imageHeight * 4];
		status = clEnqueueReadImage(commandQueue, outputImage2DBuffer, CL_TRUE, origin, region, 0, 0, outputImagePixels, 0, NULL, NULL);
		Bitmap^ bmpOutputImage = gcnew Bitmap(imageWidth, imageHeight);
		unsigned char* p = &outputImagePixels[0];
		for (int i = 0; i < imageHeight; i++)
		{
			for (int j = 0; j < imageWidth; j++)
			{
				unsigned int temp = *p++ << 24;
				temp |= (*p++ << 16);
				temp |= (*p++ << 8);
				temp |= *p++;
				bmpOutputImage->SetPixel(j, i, Color::FromArgb(temp));
			}
		}
		pbOpenCL->Image = bmpOutputImage; // Вывод полученного изображения на экран
		clReleaseMemObject(outputImage2DBuffer);
		clReleaseMemObject(inputImage2DBuffer);
		delete[]inputImagePixels;
		delete[]outputImagePixels;
		clReleaseKernel(kernel);
		clReleaseCommandQueue(commandQueue);
		clReleaseContext(context);
		clReleaseProgram(program);
	}

	/// <summary>
	/// Метод для инициализации устройства OpenCL
	/// </summary>
	private: void configureDevices() 
	{
		cl_uint numberOfPlatforms;
		cl_platform_id platform = NULL;
		cl_int status = clGetPlatformIDs(0, NULL, &numberOfPlatforms);
		if (numberOfPlatforms > 0)
		{
			cl_platform_id* platforms = new cl_platform_id[numberOfPlatforms];
			status = clGetPlatformIDs(numberOfPlatforms, platforms, NULL);
			platform = platforms[0];
			delete[] platforms;
		}
		cl_uint numberOfDevices = 0;
		status = clGetDeviceIDs(platform, CL_DEVICE_TYPE_ALL, 0, NULL, &numberOfDevices);
		if (status != CL_SUCCESS)
		{
			System::Windows::Forms::MessageBox::Show("Устройство для OpenCL не обнаружено", "Ошибка", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
			return;
		}
		this->devices = new cl_device_id[numberOfDevices];
		status = clGetDeviceIDs(platform, CL_DEVICE_TYPE_ALL, numberOfDevices, this->devices, NULL);
		if (status != CL_SUCCESS)
		{
			System::Windows::Forms::MessageBox::Show("Устройство для OpenCL не обнаружено", "Ошибка", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Error);
			return;
		}
		System::Windows::Forms::MessageBox::Show("Устройство для OpenCL успешно настроено", "Успех", System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Information);
	}

	/// <summary>
	/// Метод преобразования файла CL в читаемый формат для CL
	/// </summary>
	private: int convertToString(const char* fileName, string& s)
	{
		size_t size; char* str;
		fstream f(fileName, (std::fstream::in | std::fstream::binary));
		if (f.is_open())
		{
			size_t fileSize; f.seekg(0, fstream::end);
			size = fileSize = (size_t)f.tellg();
			f.seekg(0, fstream::beg);
			str = new char[size + 1];
			if (!str)
			{
				f.close();
				return 0;
			}
			f.read(str, fileSize);
			f.close();
			str[size] = '\0';
			s = str;
			delete[] str;
			return 0;
		}
		return -1;
	}


	private: System::Void MyForm_Shown(System::Object^ sender, System::EventArgs^ e) {
		configureDevices();
	}

	private: System::Void btnSaveCPU_Click(System::Object^ sender, System::EventArgs^ e) {
		SavePictureFromPb(pbCPU);
	}

	private: System::Void btnSaveMP_Click(System::Object^ sender, System::EventArgs^ e) {
		SavePictureFromPb(pbOpenMP);
	}

	private: System::Void btnSaveCL_Click(System::Object^ sender, System::EventArgs^ e) {
		SavePictureFromPb(pbOpenCL);
	}

	private: void SavePictureFromPb(PictureBox^ pb)
	{
		saveFileDialogPicture->Title = "Save image";
		saveFileDialogPicture->Filter = "Images (*.bmp, *.jpg, *.jpeg) | *.jpg;*.bmp;*.jpeg";
		if (saveFileDialogPicture->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			Bitmap^ bitmap = gcnew Bitmap(pb->Image);
			bitmap->Save(saveFileDialogPicture->FileName);
		}
	}

};
}
