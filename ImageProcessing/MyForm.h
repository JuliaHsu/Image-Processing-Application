#pragma once
#include <cmath>
#include<ctime>
#include<algorithm>
//using namespace std;

namespace hw1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Imaging;

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

	public:
		int imW;
		int imH;
		int maskSize;
		PixelFormat myPixelFormat;
		int** arrayR;
		int** arrayG; 
		int** arrayB;
		int** arrayGray;
		int T=128;
		Bitmap^ myBitmap;
	private: System::Windows::Forms::ToolStripButton^  toolStripButtonSP;
	public:
	private: System::Windows::Forms::Label^  lb_noise;
	private: System::Windows::Forms::TextBox^  textBoxNoise;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton1;
	private: System::Windows::Forms::Label^  lb_sigma;
	private: System::Windows::Forms::TextBox^  textBoxSigma;
	private: System::Windows::Forms::ToolStripMenuItem^  filteringToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  averageFilterToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  gaussianFilterToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  enhancementToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  histogramEqualizationToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saltAndPepperNoiseToolStripMenuItem;
	private: System::Windows::Forms::ToolStripButton^  toolStripButtonUnsharp;
	private: System::Windows::Forms::ToolStripButton^  toolStripButtonMedian;
	private: System::Windows::Forms::HScrollBar^  hScrollBarT;
	private: System::Windows::Forms::Label^  lbThreshold;
	private: System::Windows::Forms::Label^  lbThresholdVal;
	private: System::Windows::Forms::CheckBox^  checkBoxShowT;
	private: System::Windows::Forms::ToolStripButton^  toolStripButtonbin;
	private: System::Windows::Forms::ToolStripButton^  toolStripButtonLaplacian;
	private: System::Windows::Forms::ToolStripButton^  toolStripButtonOtsu;
	private: System::Windows::Forms::ToolStripButton^  toolStripButtonSobel;
	private: System::Windows::Forms::ToolStripButton^  toolStripButtonThinning;
	private: System::Windows::Forms::ToolStripButton^  toolStripButtonRotate;
	private: System::Windows::Forms::Label^  lb_rotate;
	private: System::Windows::Forms::TextBox^  textBoxRotate;

			 bool openFile;
		

		
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
	private: System::Windows::Forms::PictureBox^  pictureBoxBefore;
	private: System::Windows::Forms::PictureBox^  pictureBoxAfter;
	private: System::Windows::Forms::ToolStrip^  toolStrip;


	private: System::Windows::Forms::ToolStripButton^  toolStripOpen;
	private: System::Windows::Forms::ToolStripButton^  toolStripSave;
	private: System::Windows::Forms::ToolStripButton^  toolStripExit;
	private: System::Windows::Forms::ToolStripButton^  toolStripUndo;
	private: System::Windows::Forms::ToolStripButton^  toolStripInverse;
	private: System::Windows::Forms::ToolStripButton^  toolStripGray;

	private: System::Windows::Forms::PictureBox^  pictureBoxHisto;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Label^  lbOrginal;
	private: System::Windows::Forms::Label^  lbHisto;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveAsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  editToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  inverseToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  grayToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  undoToolStripMenuItem;
	private: System::Windows::Forms::Label^  lb_width;
	private: System::Windows::Forms::Label^  lb_height;
	private: System::Windows::Forms::Label^  lb_imageFormat;
	private: System::Windows::Forms::ToolStripButton^  toolStripButtonHistogram;
	private: System::Windows::Forms::ComboBox^  comboBoxHistogram;
	private: System::Windows::Forms::Label^  lb_histoX;
	private: System::Windows::Forms::Label^  lb_histoY;
	private: System::Windows::Forms::ToolStripButton^  toolStripButtonHistoEq;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::RadioButton^  radioButton9x9;
	private: System::Windows::Forms::RadioButton^  radioButton7x7;
	private: System::Windows::Forms::RadioButton^  radioButton5x5;
	private: System::Windows::Forms::RadioButton^  radioButton3x3;
	private: System::Windows::Forms::ToolStripButton^  toolStripAvFilter;
	private: System::Windows::Forms::Label^  lbTarget;


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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->pictureBoxBefore = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxAfter = (gcnew System::Windows::Forms::PictureBox());
			this->toolStrip = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripOpen = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSave = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripExit = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripUndo = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripInverse = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripGray = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButtonHistogram = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButtonHistoEq = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripAvFilter = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButtonSP = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton1 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButtonUnsharp = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButtonMedian = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButtonbin = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButtonLaplacian = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButtonOtsu = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButtonSobel = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButtonThinning = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButtonRotate = (gcnew System::Windows::Forms::ToolStripButton());
			this->pictureBoxHisto = (gcnew System::Windows::Forms::PictureBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->lbOrginal = (gcnew System::Windows::Forms::Label());
			this->lbHisto = (gcnew System::Windows::Forms::Label());
			this->lbTarget = (gcnew System::Windows::Forms::Label());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveAsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->editToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->undoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->inverseToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->grayToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->filteringToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->averageFilterToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->gaussianFilterToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->enhancementToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->histogramEqualizationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saltAndPepperNoiseToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->lb_width = (gcnew System::Windows::Forms::Label());
			this->lb_height = (gcnew System::Windows::Forms::Label());
			this->lb_imageFormat = (gcnew System::Windows::Forms::Label());
			this->comboBoxHistogram = (gcnew System::Windows::Forms::ComboBox());
			this->lb_histoX = (gcnew System::Windows::Forms::Label());
			this->lb_histoY = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton9x9 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton7x7 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton5x5 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3x3 = (gcnew System::Windows::Forms::RadioButton());
			this->lb_noise = (gcnew System::Windows::Forms::Label());
			this->textBoxNoise = (gcnew System::Windows::Forms::TextBox());
			this->lb_sigma = (gcnew System::Windows::Forms::Label());
			this->textBoxSigma = (gcnew System::Windows::Forms::TextBox());
			this->hScrollBarT = (gcnew System::Windows::Forms::HScrollBar());
			this->lbThreshold = (gcnew System::Windows::Forms::Label());
			this->lbThresholdVal = (gcnew System::Windows::Forms::Label());
			this->checkBoxShowT = (gcnew System::Windows::Forms::CheckBox());
			this->lb_rotate = (gcnew System::Windows::Forms::Label());
			this->textBoxRotate = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxBefore))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxAfter))->BeginInit();
			this->toolStrip->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxHisto))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBoxBefore
			// 
			this->pictureBoxBefore->Location = System::Drawing::Point(29, 75);
			this->pictureBoxBefore->Name = L"pictureBoxBefore";
			this->pictureBoxBefore->Size = System::Drawing::Size(256, 256);
			this->pictureBoxBefore->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxBefore->TabIndex = 0;
			this->pictureBoxBefore->TabStop = false;
			// 
			// pictureBoxAfter
			// 
			this->pictureBoxAfter->Location = System::Drawing::Point(769, 75);
			this->pictureBoxAfter->Name = L"pictureBoxAfter";
			this->pictureBoxAfter->Size = System::Drawing::Size(256, 256);
			this->pictureBoxAfter->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxAfter->TabIndex = 1;
			this->pictureBoxAfter->TabStop = false;
			// 
			// toolStrip
			// 
			this->toolStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(19) {
				this->toolStripOpen, this->toolStripSave,
					this->toolStripExit, this->toolStripUndo, this->toolStripInverse, this->toolStripGray, this->toolStripButtonHistogram, this->toolStripButtonHistoEq,
					this->toolStripAvFilter, this->toolStripButtonSP, this->toolStripButton1, this->toolStripButtonUnsharp, this->toolStripButtonMedian,
					this->toolStripButtonbin, this->toolStripButtonLaplacian, this->toolStripButtonOtsu, this->toolStripButtonSobel, this->toolStripButtonThinning,
					this->toolStripButtonRotate
			});
			this->toolStrip->Location = System::Drawing::Point(0, 24);
			this->toolStrip->Name = L"toolStrip";
			this->toolStrip->Size = System::Drawing::Size(1105, 25);
			this->toolStrip->TabIndex = 7;
			this->toolStrip->Text = L"toolStrip1";
			// 
			// toolStripOpen
			// 
			this->toolStripOpen->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripOpen->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripOpen.Image")));
			this->toolStripOpen->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripOpen->Name = L"toolStripOpen";
			this->toolStripOpen->Size = System::Drawing::Size(23, 22);
			this->toolStripOpen->Text = L"Open";
			this->toolStripOpen->Click += gcnew System::EventHandler(this, &MyForm::toolStripOpen_Click);
			// 
			// toolStripSave
			// 
			this->toolStripSave->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripSave->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripSave.Image")));
			this->toolStripSave->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripSave->Name = L"toolStripSave";
			this->toolStripSave->Size = System::Drawing::Size(23, 22);
			this->toolStripSave->Text = L"Save As";
			this->toolStripSave->Click += gcnew System::EventHandler(this, &MyForm::toolStripSave_Click);
			// 
			// toolStripExit
			// 
			this->toolStripExit->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripExit->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripExit.Image")));
			this->toolStripExit->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripExit->Name = L"toolStripExit";
			this->toolStripExit->Size = System::Drawing::Size(23, 22);
			this->toolStripExit->Text = L"Exit";
			this->toolStripExit->ToolTipText = L"Exit";
			this->toolStripExit->Click += gcnew System::EventHandler(this, &MyForm::toolStripExit_Click);
			// 
			// toolStripUndo
			// 
			this->toolStripUndo->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripUndo->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripUndo.Image")));
			this->toolStripUndo->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripUndo->Name = L"toolStripUndo";
			this->toolStripUndo->Size = System::Drawing::Size(23, 22);
			this->toolStripUndo->Text = L"Undo";
			this->toolStripUndo->Click += gcnew System::EventHandler(this, &MyForm::toolStripUndo_Click);
			// 
			// toolStripInverse
			// 
			this->toolStripInverse->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripInverse->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripInverse.Image")));
			this->toolStripInverse->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripInverse->Name = L"toolStripInverse";
			this->toolStripInverse->Size = System::Drawing::Size(23, 22);
			this->toolStripInverse->Text = L"Inverse";
			this->toolStripInverse->Click += gcnew System::EventHandler(this, &MyForm::toolStripInverse_Click);
			// 
			// toolStripGray
			// 
			this->toolStripGray->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripGray->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripGray.Image")));
			this->toolStripGray->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripGray->Name = L"toolStripGray";
			this->toolStripGray->Size = System::Drawing::Size(23, 22);
			this->toolStripGray->Text = L"Gray";
			this->toolStripGray->Click += gcnew System::EventHandler(this, &MyForm::toolStripGray_Click);
			// 
			// toolStripButtonHistogram
			// 
			this->toolStripButtonHistogram->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButtonHistogram->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButtonHistogram.Image")));
			this->toolStripButtonHistogram->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButtonHistogram->Name = L"toolStripButtonHistogram";
			this->toolStripButtonHistogram->Size = System::Drawing::Size(23, 22);
			this->toolStripButtonHistogram->Text = L"Histogram";
			this->toolStripButtonHistogram->Click += gcnew System::EventHandler(this, &MyForm::toolStripButtonHistogram_Click);
			// 
			// toolStripButtonHistoEq
			// 
			this->toolStripButtonHistoEq->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButtonHistoEq->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButtonHistoEq.Image")));
			this->toolStripButtonHistoEq->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButtonHistoEq->Name = L"toolStripButtonHistoEq";
			this->toolStripButtonHistoEq->Size = System::Drawing::Size(23, 22);
			this->toolStripButtonHistoEq->Text = L"Histogram Equalization";
			this->toolStripButtonHistoEq->Click += gcnew System::EventHandler(this, &MyForm::toolStripButtonHistoEq_Click);
			// 
			// toolStripAvFilter
			// 
			this->toolStripAvFilter->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripAvFilter->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripAvFilter.Image")));
			this->toolStripAvFilter->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripAvFilter->Name = L"toolStripAvFilter";
			this->toolStripAvFilter->Size = System::Drawing::Size(23, 22);
			this->toolStripAvFilter->Text = L"Average Filter";
			this->toolStripAvFilter->Click += gcnew System::EventHandler(this, &MyForm::toolStripAvFilter_Click);
			// 
			// toolStripButtonSP
			// 
			this->toolStripButtonSP->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButtonSP->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButtonSP.Image")));
			this->toolStripButtonSP->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButtonSP->Name = L"toolStripButtonSP";
			this->toolStripButtonSP->Size = System::Drawing::Size(23, 22);
			this->toolStripButtonSP->Text = L"Salt pepper Noise";
			this->toolStripButtonSP->Click += gcnew System::EventHandler(this, &MyForm::toolStripButtonSP_Click);
			// 
			// toolStripButton1
			// 
			this->toolStripButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton1.Image")));
			this->toolStripButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton1->Name = L"toolStripButton1";
			this->toolStripButton1->Size = System::Drawing::Size(23, 22);
			this->toolStripButton1->Text = L"Gaussian Filter";
			this->toolStripButton1->Click += gcnew System::EventHandler(this, &MyForm::toolStripButton1_Click);
			// 
			// toolStripButtonUnsharp
			// 
			this->toolStripButtonUnsharp->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButtonUnsharp->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButtonUnsharp.Image")));
			this->toolStripButtonUnsharp->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButtonUnsharp->Name = L"toolStripButtonUnsharp";
			this->toolStripButtonUnsharp->Size = System::Drawing::Size(23, 22);
			this->toolStripButtonUnsharp->Text = L"Unsharp";
			this->toolStripButtonUnsharp->Click += gcnew System::EventHandler(this, &MyForm::toolStripButtonUnsharp_Click);
			// 
			// toolStripButtonMedian
			// 
			this->toolStripButtonMedian->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButtonMedian->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButtonMedian.Image")));
			this->toolStripButtonMedian->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButtonMedian->Name = L"toolStripButtonMedian";
			this->toolStripButtonMedian->Size = System::Drawing::Size(23, 22);
			this->toolStripButtonMedian->Text = L"Median";
			this->toolStripButtonMedian->Click += gcnew System::EventHandler(this, &MyForm::toolStripButtonMedian_Click);
			// 
			// toolStripButtonbin
			// 
			this->toolStripButtonbin->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButtonbin->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButtonbin.Image")));
			this->toolStripButtonbin->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButtonbin->Name = L"toolStripButtonbin";
			this->toolStripButtonbin->Size = System::Drawing::Size(23, 22);
			this->toolStripButtonbin->Text = L"Binarization";
			this->toolStripButtonbin->Click += gcnew System::EventHandler(this, &MyForm::toolStripButtonbin_Click);
			// 
			// toolStripButtonLaplacian
			// 
			this->toolStripButtonLaplacian->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButtonLaplacian->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButtonLaplacian.Image")));
			this->toolStripButtonLaplacian->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButtonLaplacian->Name = L"toolStripButtonLaplacian";
			this->toolStripButtonLaplacian->Size = System::Drawing::Size(23, 22);
			this->toolStripButtonLaplacian->Text = L"Laplacian";
			this->toolStripButtonLaplacian->Click += gcnew System::EventHandler(this, &MyForm::toolStripButtonLaplacian_Click);
			// 
			// toolStripButtonOtsu
			// 
			this->toolStripButtonOtsu->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButtonOtsu->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButtonOtsu.Image")));
			this->toolStripButtonOtsu->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButtonOtsu->Name = L"toolStripButtonOtsu";
			this->toolStripButtonOtsu->Size = System::Drawing::Size(23, 22);
			this->toolStripButtonOtsu->Text = L"Otsu";
			this->toolStripButtonOtsu->Click += gcnew System::EventHandler(this, &MyForm::toolStripButtonOtsu_Click);
			// 
			// toolStripButtonSobel
			// 
			this->toolStripButtonSobel->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButtonSobel->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButtonSobel.Image")));
			this->toolStripButtonSobel->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButtonSobel->Name = L"toolStripButtonSobel";
			this->toolStripButtonSobel->Size = System::Drawing::Size(23, 22);
			this->toolStripButtonSobel->Text = L"Sobel";
			this->toolStripButtonSobel->Click += gcnew System::EventHandler(this, &MyForm::toolStripButtonSobel_Click);
			// 
			// toolStripButtonThinning
			// 
			this->toolStripButtonThinning->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButtonThinning->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButtonThinning.Image")));
			this->toolStripButtonThinning->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButtonThinning->Name = L"toolStripButtonThinning";
			this->toolStripButtonThinning->Size = System::Drawing::Size(23, 22);
			this->toolStripButtonThinning->Text = L"toolStripButtonThinning";
			this->toolStripButtonThinning->Click += gcnew System::EventHandler(this, &MyForm::toolStripButtonThinning_Click);
			// 
			// toolStripButtonRotate
			// 
			this->toolStripButtonRotate->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButtonRotate->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButtonRotate.Image")));
			this->toolStripButtonRotate->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButtonRotate->Name = L"toolStripButtonRotate";
			this->toolStripButtonRotate->Size = System::Drawing::Size(23, 22);
			this->toolStripButtonRotate->Text = L"Rotate";
			this->toolStripButtonRotate->Click += gcnew System::EventHandler(this, &MyForm::toolStripButtonRotate_Click);
			// 
			// pictureBoxHisto
			// 
			this->pictureBoxHisto->Location = System::Drawing::Point(409, 75);
			this->pictureBoxHisto->Name = L"pictureBoxHisto";
			this->pictureBoxHisto->Size = System::Drawing::Size(256, 256);
			this->pictureBoxHisto->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBoxHisto->TabIndex = 8;
			this->pictureBoxHisto->TabStop = false;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// lbOrginal
			// 
			this->lbOrginal->AutoSize = true;
			this->lbOrginal->Location = System::Drawing::Point(132, 383);
			this->lbOrginal->Name = L"lbOrginal";
			this->lbOrginal->Size = System::Drawing::Size(40, 12);
			this->lbOrginal->TabIndex = 10;
			this->lbOrginal->Text = L"Orginal";
			// 
			// lbHisto
			// 
			this->lbHisto->AutoSize = true;
			this->lbHisto->Location = System::Drawing::Point(513, 383);
			this->lbHisto->Name = L"lbHisto";
			this->lbHisto->Size = System::Drawing::Size(53, 12);
			this->lbHisto->TabIndex = 11;
			this->lbHisto->Text = L"Histogram";
			// 
			// lbTarget
			// 
			this->lbTarget->AutoSize = true;
			this->lbTarget->Location = System::Drawing::Point(901, 383);
			this->lbTarget->Name = L"lbTarget";
			this->lbTarget->Size = System::Drawing::Size(35, 12);
			this->lbTarget->TabIndex = 12;
			this->lbTarget->Text = L"Target";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->fileToolStripMenuItem,
					this->editToolStripMenuItem, this->filteringToolStripMenuItem, this->enhancementToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1105, 24);
			this->menuStrip1->TabIndex = 13;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->openToolStripMenuItem,
					this->saveAsToolStripMenuItem, this->exitToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(38, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(117, 22);
			this->openToolStripMenuItem->Text = L"Open";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::openToolStripMenuItem_Click);
			// 
			// saveAsToolStripMenuItem
			// 
			this->saveAsToolStripMenuItem->Name = L"saveAsToolStripMenuItem";
			this->saveAsToolStripMenuItem->Size = System::Drawing::Size(117, 22);
			this->saveAsToolStripMenuItem->Text = L"Save As";
			this->saveAsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::saveAsToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(117, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::exitToolStripMenuItem_Click_1);
			// 
			// editToolStripMenuItem
			// 
			this->editToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->undoToolStripMenuItem,
					this->inverseToolStripMenuItem, this->grayToolStripMenuItem
			});
			this->editToolStripMenuItem->Name = L"editToolStripMenuItem";
			this->editToolStripMenuItem->Size = System::Drawing::Size(41, 20);
			this->editToolStripMenuItem->Text = L"Edit";
			// 
			// undoToolStripMenuItem
			// 
			this->undoToolStripMenuItem->Name = L"undoToolStripMenuItem";
			this->undoToolStripMenuItem->Size = System::Drawing::Size(113, 22);
			this->undoToolStripMenuItem->Text = L"Undo";
			this->undoToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::undoToolStripMenuItem_Click);
			// 
			// inverseToolStripMenuItem
			// 
			this->inverseToolStripMenuItem->Name = L"inverseToolStripMenuItem";
			this->inverseToolStripMenuItem->Size = System::Drawing::Size(113, 22);
			this->inverseToolStripMenuItem->Text = L"Inverse";
			this->inverseToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::inverseToolStripMenuItem_Click);
			// 
			// grayToolStripMenuItem
			// 
			this->grayToolStripMenuItem->Name = L"grayToolStripMenuItem";
			this->grayToolStripMenuItem->Size = System::Drawing::Size(113, 22);
			this->grayToolStripMenuItem->Text = L"Gray";
			this->grayToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::grayToolStripMenuItem_Click);
			// 
			// filteringToolStripMenuItem
			// 
			this->filteringToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->averageFilterToolStripMenuItem,
					this->gaussianFilterToolStripMenuItem
			});
			this->filteringToolStripMenuItem->Name = L"filteringToolStripMenuItem";
			this->filteringToolStripMenuItem->Size = System::Drawing::Size(64, 20);
			this->filteringToolStripMenuItem->Text = L"Filtering";
			// 
			// averageFilterToolStripMenuItem
			// 
			this->averageFilterToolStripMenuItem->Name = L"averageFilterToolStripMenuItem";
			this->averageFilterToolStripMenuItem->Size = System::Drawing::Size(154, 22);
			this->averageFilterToolStripMenuItem->Text = L"Average Filter";
			this->averageFilterToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::averageFilterToolStripMenuItem_Click);
			// 
			// gaussianFilterToolStripMenuItem
			// 
			this->gaussianFilterToolStripMenuItem->Name = L"gaussianFilterToolStripMenuItem";
			this->gaussianFilterToolStripMenuItem->Size = System::Drawing::Size(154, 22);
			this->gaussianFilterToolStripMenuItem->Text = L"Gaussian Filter";
			this->gaussianFilterToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::gaussianFilterToolStripMenuItem_Click);
			// 
			// enhancementToolStripMenuItem
			// 
			this->enhancementToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->histogramEqualizationToolStripMenuItem,
					this->saltAndPepperNoiseToolStripMenuItem
			});
			this->enhancementToolStripMenuItem->Name = L"enhancementToolStripMenuItem";
			this->enhancementToolStripMenuItem->Size = System::Drawing::Size(96, 20);
			this->enhancementToolStripMenuItem->Text = L"Enhancement";
			// 
			// histogramEqualizationToolStripMenuItem
			// 
			this->histogramEqualizationToolStripMenuItem->Name = L"histogramEqualizationToolStripMenuItem";
			this->histogramEqualizationToolStripMenuItem->Size = System::Drawing::Size(206, 22);
			this->histogramEqualizationToolStripMenuItem->Text = L"Histogram Equalization";
			this->histogramEqualizationToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::histogramEqualizationToolStripMenuItem_Click);
			// 
			// saltAndPepperNoiseToolStripMenuItem
			// 
			this->saltAndPepperNoiseToolStripMenuItem->Name = L"saltAndPepperNoiseToolStripMenuItem";
			this->saltAndPepperNoiseToolStripMenuItem->Size = System::Drawing::Size(206, 22);
			this->saltAndPepperNoiseToolStripMenuItem->Text = L"Salt and Pepper Noise";
			this->saltAndPepperNoiseToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::saltAndPepperNoiseToolStripMenuItem_Click);
			// 
			// lb_width
			// 
			this->lb_width->AutoSize = true;
			this->lb_width->Location = System::Drawing::Point(294, 330);
			this->lb_width->Name = L"lb_width";
			this->lb_width->Size = System::Drawing::Size(33, 12);
			this->lb_width->TabIndex = 14;
			this->lb_width->Text = L"label1";
			// 
			// lb_height
			// 
			this->lb_height->AutoSize = true;
			this->lb_height->Location = System::Drawing::Point(-2, 60);
			this->lb_height->Name = L"lb_height";
			this->lb_height->Size = System::Drawing::Size(33, 12);
			this->lb_height->TabIndex = 15;
			this->lb_height->Text = L"label2";
			// 
			// lb_imageFormat
			// 
			this->lb_imageFormat->AutoSize = true;
			this->lb_imageFormat->Location = System::Drawing::Point(132, 411);
			this->lb_imageFormat->Name = L"lb_imageFormat";
			this->lb_imageFormat->Size = System::Drawing::Size(33, 12);
			this->lb_imageFormat->TabIndex = 16;
			this->lb_imageFormat->Text = L"label1";
			// 
			// comboBoxHistogram
			// 
			this->comboBoxHistogram->FormattingEnabled = true;
			this->comboBoxHistogram->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"R", L"G", L"B", L"Y" });
			this->comboBoxHistogram->Location = System::Drawing::Point(476, 421);
			this->comboBoxHistogram->Name = L"comboBoxHistogram";
			this->comboBoxHistogram->Size = System::Drawing::Size(121, 20);
			this->comboBoxHistogram->TabIndex = 17;
			this->comboBoxHistogram->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBoxHistogram_SelectedIndexChanged);
			// 
			// lb_histoX
			// 
			this->lb_histoX->AutoSize = true;
			this->lb_histoX->Location = System::Drawing::Point(675, 339);
			this->lb_histoX->Name = L"lb_histoX";
			this->lb_histoX->Size = System::Drawing::Size(23, 12);
			this->lb_histoX->TabIndex = 18;
			this->lb_histoX->Text = L"255";
			// 
			// lb_histoY
			// 
			this->lb_histoY->AutoSize = true;
			this->lb_histoY->Location = System::Drawing::Point(380, 75);
			this->lb_histoY->Name = L"lb_histoY";
			this->lb_histoY->Size = System::Drawing::Size(0, 12);
			this->lb_histoY->TabIndex = 19;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->radioButton9x9);
			this->groupBox1->Controls->Add(this->radioButton7x7);
			this->groupBox1->Controls->Add(this->radioButton5x5);
			this->groupBox1->Controls->Add(this->radioButton3x3);
			this->groupBox1->Location = System::Drawing::Point(769, 398);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(256, 55);
			this->groupBox1->TabIndex = 20;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Mask Size";
			// 
			// radioButton9x9
			// 
			this->radioButton9x9->AutoSize = true;
			this->radioButton9x9->Location = System::Drawing::Point(161, 27);
			this->radioButton9x9->Name = L"radioButton9x9";
			this->radioButton9x9->Size = System::Drawing::Size(41, 16);
			this->radioButton9x9->TabIndex = 3;
			this->radioButton9x9->Text = L"9*9";
			this->radioButton9x9->UseVisualStyleBackColor = true;
			// 
			// radioButton7x7
			// 
			this->radioButton7x7->AutoSize = true;
			this->radioButton7x7->Location = System::Drawing::Point(114, 27);
			this->radioButton7x7->Name = L"radioButton7x7";
			this->radioButton7x7->Size = System::Drawing::Size(41, 16);
			this->radioButton7x7->TabIndex = 2;
			this->radioButton7x7->Text = L"7*7";
			this->radioButton7x7->UseVisualStyleBackColor = true;
			// 
			// radioButton5x5
			// 
			this->radioButton5x5->AutoSize = true;
			this->radioButton5x5->Location = System::Drawing::Point(67, 27);
			this->radioButton5x5->Name = L"radioButton5x5";
			this->radioButton5x5->Size = System::Drawing::Size(41, 16);
			this->radioButton5x5->TabIndex = 1;
			this->radioButton5x5->Text = L"5*5";
			this->radioButton5x5->UseVisualStyleBackColor = true;
			// 
			// radioButton3x3
			// 
			this->radioButton3x3->AutoSize = true;
			this->radioButton3x3->Checked = true;
			this->radioButton3x3->Location = System::Drawing::Point(20, 27);
			this->radioButton3x3->Name = L"radioButton3x3";
			this->radioButton3x3->Size = System::Drawing::Size(41, 16);
			this->radioButton3x3->TabIndex = 0;
			this->radioButton3x3->TabStop = true;
			this->radioButton3x3->Text = L"3*3";
			this->radioButton3x3->UseVisualStyleBackColor = true;
			// 
			// lb_noise
			// 
			this->lb_noise->AutoSize = true;
			this->lb_noise->Location = System::Drawing::Point(27, 441);
			this->lb_noise->Name = L"lb_noise";
			this->lb_noise->Size = System::Drawing::Size(48, 12);
			this->lb_noise->TabIndex = 21;
			this->lb_noise->Text = L"Noise(%)";
			// 
			// textBoxNoise
			// 
			this->textBoxNoise->Location = System::Drawing::Point(101, 438);
			this->textBoxNoise->Name = L"textBoxNoise";
			this->textBoxNoise->Size = System::Drawing::Size(100, 22);
			this->textBoxNoise->TabIndex = 22;
			this->textBoxNoise->Text = L"5.0";
			// 
			// lb_sigma
			// 
			this->lb_sigma->AutoSize = true;
			this->lb_sigma->Location = System::Drawing::Point(767, 466);
			this->lb_sigma->Name = L"lb_sigma";
			this->lb_sigma->Size = System::Drawing::Size(37, 12);
			this->lb_sigma->TabIndex = 23;
			this->lb_sigma->Text = L"Sigma:";
			// 
			// textBoxSigma
			// 
			this->textBoxSigma->Location = System::Drawing::Point(824, 459);
			this->textBoxSigma->Name = L"textBoxSigma";
			this->textBoxSigma->Size = System::Drawing::Size(100, 22);
			this->textBoxSigma->TabIndex = 24;
			this->textBoxSigma->Text = L"1.0";
			// 
			// hScrollBarT
			// 
			this->hScrollBarT->LargeChange = 1;
			this->hScrollBarT->Location = System::Drawing::Point(409, 486);
			this->hScrollBarT->Maximum = 255;
			this->hScrollBarT->Name = L"hScrollBarT";
			this->hScrollBarT->Size = System::Drawing::Size(256, 31);
			this->hScrollBarT->TabIndex = 25;
			this->hScrollBarT->Value = 128;
			this->hScrollBarT->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &MyForm::hScrollBarT_Scroll);
			// 
			// lbThreshold
			// 
			this->lbThreshold->AutoSize = true;
			this->lbThreshold->Location = System::Drawing::Point(408, 462);
			this->lbThreshold->Name = L"lbThreshold";
			this->lbThreshold->Size = System::Drawing::Size(55, 12);
			this->lbThreshold->TabIndex = 26;
			this->lbThreshold->Text = L"Threshold:";
			// 
			// lbThresholdVal
			// 
			this->lbThresholdVal->AutoSize = true;
			this->lbThresholdVal->Location = System::Drawing::Point(484, 460);
			this->lbThresholdVal->Name = L"lbThresholdVal";
			this->lbThresholdVal->Size = System::Drawing::Size(23, 12);
			this->lbThresholdVal->TabIndex = 27;
			this->lbThresholdVal->Text = L"128";
			// 
			// checkBoxShowT
			// 
			this->checkBoxShowT->AutoSize = true;
			this->checkBoxShowT->Checked = true;
			this->checkBoxShowT->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBoxShowT->Location = System::Drawing::Point(588, 460);
			this->checkBoxShowT->Name = L"checkBoxShowT";
			this->checkBoxShowT->Size = System::Drawing::Size(100, 16);
			this->checkBoxShowT->TabIndex = 28;
			this->checkBoxShowT->Text = L"Show Threshold";
			this->checkBoxShowT->UseVisualStyleBackColor = true;
			// 
			// lb_rotate
			// 
			this->lb_rotate->AutoSize = true;
			this->lb_rotate->Location = System::Drawing::Point(27, 486);
			this->lb_rotate->Name = L"lb_rotate";
			this->lb_rotate->Size = System::Drawing::Size(38, 12);
			this->lb_rotate->TabIndex = 29;
			this->lb_rotate->Text = L"Rotate:";
			// 
			// textBoxRotate
			// 
			this->textBoxRotate->Location = System::Drawing::Point(101, 483);
			this->textBoxRotate->Name = L"textBoxRotate";
			this->textBoxRotate->Size = System::Drawing::Size(100, 22);
			this->textBoxRotate->TabIndex = 30;
			this->textBoxRotate->Text = L"45.0";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1105, 535);
			this->Controls->Add(this->textBoxRotate);
			this->Controls->Add(this->lb_rotate);
			this->Controls->Add(this->checkBoxShowT);
			this->Controls->Add(this->lbThresholdVal);
			this->Controls->Add(this->lbThreshold);
			this->Controls->Add(this->hScrollBarT);
			this->Controls->Add(this->textBoxSigma);
			this->Controls->Add(this->lb_sigma);
			this->Controls->Add(this->textBoxNoise);
			this->Controls->Add(this->lb_noise);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->lb_histoY);
			this->Controls->Add(this->lb_histoX);
			this->Controls->Add(this->comboBoxHistogram);
			this->Controls->Add(this->lb_imageFormat);
			this->Controls->Add(this->lb_height);
			this->Controls->Add(this->lb_width);
			this->Controls->Add(this->lbTarget);
			this->Controls->Add(this->lbHisto);
			this->Controls->Add(this->lbOrginal);
			this->Controls->Add(this->pictureBoxHisto);
			this->Controls->Add(this->toolStrip);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->pictureBoxAfter);
			this->Controls->Add(this->pictureBoxBefore);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"Image Processing";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxBefore))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxAfter))->EndInit();
			this->toolStrip->ResumeLayout(false);
			this->toolStrip->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxHisto))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void toolStripOpen_Click(System::Object^  sender, System::EventArgs^  e) {
		openFileDialog1->Filter = "Bitmap Image|*.bmp|All Files|*.*";
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			pictureBoxBefore->ImageLocation = openFileDialog1->FileName;
		}
		else {
			//MessageBox::Show(¡§open image error¡¨); // open image error
		}
		myBitmap = gcnew Bitmap(pictureBoxBefore->ImageLocation);		imW = myBitmap->Width;		imH = myBitmap->Height;		myPixelFormat = myBitmap->PixelFormat;
		//lock
		Rectangle rect = Rectangle(0, 0, imW, imH);
		BitmapData^ bmpData = myBitmap->LockBits(rect, ImageLockMode::ReadWrite, myBitmap->PixelFormat);
		int ByteOFSkip = bmpData->Stride - bmpData->Width * 3;
		if (myBitmap->PixelFormat == PixelFormat::Format8bppIndexed)
			ByteOFSkip = bmpData->Stride - bmpData->Width;
		unsigned char* p = (unsigned char*)bmpData->Scan0.ToPointer();
		int index = 0;
		if (myBitmap->PixelFormat == PixelFormat::Format24bppRgb) {
			//new a array[Height][Width] space
			arrayB = new int*[imH];
			for (int i = 0; i < imH; i++)
				arrayB[i] = new int[imW];
			arrayG = new int*[imH];
			for (int i = 0; i < imH; i++)
				arrayG[i] = new int[imW];
			arrayR = new int*[imH];
			for (int i = 0; i < imH; i++)
				arrayR[i] = new int[imW];
			arrayGray = new int*[imH];
			for (int i = 0; i < imH; i++)
				arrayGray[i] = new int[imW];			for (int y = 0;y < imH;y++) {				for (int x = 0;x < imW;x++) {					arrayB[y][x] = (int)p[index + 0];					arrayG[y][x] = (int)p[index + 1];					arrayR[y][x] = (int)p[index + 2];					arrayGray[y][x] = (int)(0.299*arrayR[y][x] + 0.587*arrayG[y][x] + 0.114*arrayB[y][x] + 0.5);					index += 3;				}				index +=ByteOFSkip;			}			lb_imageFormat->Text = "Color";		}		else if (myBitmap->PixelFormat == PixelFormat::Format8bppIndexed) {
			arrayGray = new int*[imH];
			for (int i = 0; i < imH; i++)
				arrayGray[i] = new int[imW];
			for (int y = 0;y < imH;y++) {
				for (int x = 0;x < imW;x++) {
					arrayGray[y][x] = (int)p[index++];
				}
				index += ByteOFSkip;
			}
			lb_imageFormat->Text = "Gray";
		}
		myBitmap->UnlockBits(bmpData);
		openFile = true;
		toolStripSave->Enabled = true;
		toolStripUndo->Enabled = true;
		toolStripInverse->Enabled = true;
		toolStripGray->Enabled = true;
		editToolStripMenuItem->Enabled = true;
		filteringToolStripMenuItem->Enabled = true;
		enhancementToolStripMenuItem->Enabled = true;
		toolStripButtonHistoEq->Enabled = true;
		toolStripButtonHistogram->Enabled = true;
		toolStripAvFilter->Enabled = true;
		toolStripButtonSP->Enabled = true;
		toolStripButton1->Enabled = true;
		toolStripButtonUnsharp->Enabled = true;
		toolStripButtonMedian->Enabled = true;
		toolStripButtonbin->Enabled = true;
		toolStripButtonLaplacian->Enabled = true;
		toolStripButtonOtsu->Enabled = true;
		toolStripButtonSobel->Enabled = true;
		comboBoxHistogram->SelectedIndex = 3;
		lb_width->Text = Convert::ToString(imW);
		lb_height->Text = Convert::ToString(imH);
		

	}
	private: System::Void toolStripSave_Click(System::Object^  sender, System::EventArgs^  e) {
		saveFileDialog1->InitialDirectory = ".\\"; //°_©l¥Ø¿ý
		saveFileDialog1->Filter = "Bitmap Image|*.bmp|All Files|*.*";
		saveFileDialog1->FilterIndex = 1;

		if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK&& saveFileDialog1->FileName->Length > 0)


			pictureBoxAfter->Image->Save(saveFileDialog1->FileName);
	}

	private: System::Void toolStripExit_Click(System::Object^  sender, System::EventArgs^  e) {
		exitToolStripMenuItem_Click(sender, e);
	}

	private:System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e){
		if (openFile) {
			if (myPixelFormat == PixelFormat::Format24bppRgb) {
				for (int i = 0;i < imH;i++)
					delete[] arrayB[i];
				delete arrayB;
				for (int i = 0;i < imH;i++)
					delete[] arrayG[i];
				delete arrayG;
				for (int i = 0;i < imH;i++)
					delete[] arrayR[i];
				delete arrayR;
				for (int i = 0;i < imH;i++)
					delete[] arrayGray[i];
				delete arrayGray;
			}
			else if (myPixelFormat == PixelFormat::Format8bppIndexed) {
				for (int i = 0;i < imH;i++)
					delete[] arrayGray[i];
				delete arrayGray;
			}
		}
		
		Application::Exit();
	}

	

	

	private: System::Void toolStripUndo_Click(System::Object^  sender, System::EventArgs^  e) {
		Bitmap ^myBitmap = gcnew Bitmap(pictureBoxBefore->ImageLocation);
		pictureBoxAfter->Image = myBitmap;
	}
	private: System::Void toolStripInverse_Click(System::Object^  sender, System::EventArgs^  e) {
		myBitmap = gcnew Bitmap(pictureBoxBefore->ImageLocation);
		myPixelFormat = myBitmap->PixelFormat;
		Rectangle rect = Rectangle(0, 0, imW, imH);
		BitmapData^ bmpData = myBitmap->LockBits(rect, ImageLockMode::ReadWrite, myBitmap->PixelFormat);
		int ByteOFSkip = bmpData->Stride - bmpData->Width * 3;
		if (myBitmap->PixelFormat == PixelFormat::Format8bppIndexed)
			ByteOFSkip = bmpData->Stride - bmpData->Width;
		unsigned char* p = (unsigned char*)bmpData->Scan0.ToPointer();
		int index = 0;
		if (myBitmap->PixelFormat == PixelFormat::Format24bppRgb) {
			for (int y = 0;y < imH;y++) {				for (int x = 0;x < imW;x++) {
					p[index] = 255 - arrayB[y][x];
					p[index + 1] = 255 - arrayG[y][x];
					p[index + 2] = 255 - arrayR[y][x];
					index += 3;
				}
				index += ByteOFSkip;
			}
		}
		else if (myBitmap->PixelFormat == PixelFormat::Format8bppIndexed) {
			for (int y = 0;y < imH;y++) {				for (int x = 0;x < imW;x++) {
					p[index++] = 255-arrayGray[y][x];
				}
				index += ByteOFSkip;
			}
			
		}
		myBitmap->UnlockBits(bmpData);
		pictureBoxAfter->Image = myBitmap;
	}
	
private: System::Void toolStripGray_Click(System::Object^  sender, System::EventArgs^  e) {
	
	if(myBitmap->PixelFormat== PixelFormat::Format24bppRgb){
		/*for (int y = 0;y < imH;y++) {
			for (int x = 0;x < imW;x++) {
				p[index] = (arrayB[y][x]+ arrayG[y][x] + arrayR[y][x] )/ 3;
				p[index + 1] = (arrayB[y][x] + arrayG[y][x] + arrayR[y][x]) / 3;
				p[index + 2] = (arrayB[y][x] + arrayG[y][x] + arrayR[y][x]) / 3;
				index += 3;
			}
			index += ByteOFSkip;
		}*/
		
		Bitmap^ myBitmapGray = gcnew Bitmap(imW,imH,PixelFormat::Format8bppIndexed);
		//gray palette
		ColorPalette^ grayP = myBitmapGray->Palette;
		for (int i = 0;i < 256;i++) {
			grayP->Entries[i] = Color::FromArgb(255, i, i, i);
		}
		myBitmapGray->Palette = grayP;

		Rectangle rect = Rectangle(0, 0, imW, imH);
		BitmapData^ bmpData2 = myBitmapGray->LockBits(rect, ImageLockMode::ReadWrite, myBitmapGray->PixelFormat);
		int ByteOfSkip2 = bmpData2->Stride - bmpData2->Width;
		unsigned char* p2 = (unsigned char*)bmpData2->Scan0.ToPointer();
		int index2=0;
	
		for (int y = 0;y < imH;y++) {
			for (int x=0;x < imW;x++) {
				//int Y = (int)(0.299*arrayR[y][x] + 0.587*arrayG[y][x] + 0.114*arrayB[y][x] + 0.5);
				//p2[index2++] = (unsigned char)Y;
				p2[index2++]=(unsigned char) arrayGray[y][x];
				
			}
			index2 += ByteOfSkip2;
		}
		
		myBitmapGray->UnlockBits(bmpData2);
		pictureBoxAfter->Image = myBitmapGray;
	}
	else if (myBitmap->PixelFormat == PixelFormat::Format8bppIndexed) {
		
		pictureBoxAfter->Image = myBitmap;
	}

}


private: System::Void openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	toolStripOpen_Click(sender, e);
}
private: System::Void saveAsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	toolStripSave_Click(sender, e);
}
private: System::Void exitToolStripMenuItem_Click_1(System::Object^  sender, System::EventArgs^  e) {
	exitToolStripMenuItem_Click(sender, e);
}
private: System::Void inverseToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	toolStripInverse_Click(sender, e);
}
private: System::Void grayToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	toolStripGray_Click(sender, e);
}
private: System::Void undoToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	toolStripUndo_Click(sender, e);
}
private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	
	toolStripSave->Enabled = false;
	toolStripUndo->Enabled = false;
	toolStripInverse->Enabled = false;
	toolStripGray->Enabled = false;
	editToolStripMenuItem->Enabled = false;
	filteringToolStripMenuItem->Enabled = false;
	enhancementToolStripMenuItem->Enabled = false;
	editToolStripMenuItem->Enabled = false;
	lb_width->Text = "";
	lb_height->Text = "";
	lb_imageFormat->Text = "";
	lb_histoX->Enabled = false;
	toolStripButtonHistoEq->Enabled = false;
	toolStripButtonHistogram->Enabled = false;
	toolStripAvFilter->Enabled = false;
	toolStripButtonSP->Enabled = false;
	toolStripButton1->Enabled = false;
	toolStripButtonUnsharp->Enabled = false;
	toolStripButtonMedian->Enabled = false;
	toolStripButtonbin->Enabled = false;
	toolStripButtonLaplacian->Enabled = false;
	toolStripButtonOtsu->Enabled = false;
	toolStripButtonSobel->Enabled = false;
	
}
private: System::Void toolStripButtonHistogram_Click(System::Object^  sender, System::EventArgs^  e) {
	comboBoxHistogram_SelectedIndexChanged(sender, e);

}
private: System::Void comboBoxHistogram_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	myBitmap = gcnew Bitmap(pictureBoxBefore->ImageLocation);
	imW = myBitmap->Width;
	imH = myBitmap->Height;
	Bitmap^ myBitmap2 = gcnew Bitmap(256, 256, PixelFormat::Format24bppRgb);
	pictureBoxHisto->Image = myBitmap2;
	Graphics^g = Graphics::FromImage(pictureBoxHisto->Image);
	Brush^ bshWt = gcnew SolidBrush(Color::White);
	g->FillRectangle(bshWt, 0, 0, 256, 256);
	Pen^ pnDraw = gcnew Pen(Color::Black);
	g->DrawLine(pnDraw, 0, 0, 0, 255);
	g->DrawLine(pnDraw, 0, 255, 255, 255);
	
	int histogramR[256];
	int histogramG[256];
	int histogramB[256];
	int histoGray[256];
	for (int i = 0; i < 256; i++) {
		histogramR[i] = 0;
		histogramG[i] = 0;
		histogramB[i] = 0;
		histoGray[i] = 0;
	}
	switch (comboBoxHistogram->SelectedIndex)
	{
			 case 0:
				 pnDraw->Color = Color::Red;
				 int r;
				 for (int y = 0; y<imH; y++) {
					 for (int x = 0; x<imW; x++) {
						 r= arrayR[y][x];
						 histogramR[r]++;
						

					 }
				 }

				 int maxR;
				 maxR = histogramR[0];
				 for (int i = 0; i < 256; i++) {

					 if (histogramR[i]>maxR) {
						 maxR = histogramR[i];
					 }

				 }

				 for (int i = 0; i < 256; i++) {
					 pnDraw->Color = Color::Red;
					 g->DrawLine(pnDraw, i, 255, i, 255 - ((double)histogramR[i] / maxR*255.0));
				 }
				 lb_histoY->Text = Convert::ToString(maxR);


				 break;
			 case 1:
				
				 int gr;
				 for (int y = 0; y<imH; y++) {
					 for (int x = 0; x<imW; x++) {
						 gr = arrayG[y][x];
						 histogramG[gr]++;


					 }
				 }
				 int maxG;
				 maxG = histogramG[0];
				 for (int i = 0; i < 256; i++) {

					 if (histogramG[i]>maxG) {
						 maxG = histogramG[i];
					 }

				 }

				 for (int i = 0; i < 256; i++) {
					 pnDraw->Color = Color::Green;
					 g->DrawLine(pnDraw, i, 255, i, 255 - ((double)histogramG[i] / maxG*255.0));
				 }
				 lb_histoY->Text = Convert::ToString(maxG);

				 break;
			 case 2:
				
				 int b;
				 for (int y = 0; y<imH; y++) {
					 for (int x = 0; x<imW; x++) {
						 b = arrayB[y][x];
						 histogramB[b]++;


					 }
				 }

				 int maxB;
				 maxB = histogramB[0];
				 for (int i = 0; i < 256; i++) {

					 if (histogramB[i]>maxB) {
						 maxB = histogramB[i];
					 }

				 }

				 for (int i = 0; i < 256; i++) {
					 pnDraw->Color = Color::Blue;
					 g->DrawLine(pnDraw, i, 255, i, 255 - ((double)histogramB[i] / maxB*255.0));
				 }
				 lb_histoY->Text = Convert::ToString(maxB);
				 break;
			 case 3:
				
				 int gray;
				 int maxy;
				 for (int y = 0; y<imH; y++) {
					 for (int x = 0; x<imW; x++) {
						 gray = arrayGray[y][x];
						 histoGray[gray]++;
					 }//for j
				 }//for i

				 maxy = histoGray[0];
				 for (int i = 0; i < 256; i++) {

					 if (histoGray[i]>maxy) {
						 maxy = histoGray[i];
					 }

				 }

				 for (int i = 0; i < 256; i++) {
					 pnDraw->Color = Color::Gray;
					 g->DrawLine(pnDraw, i, 255, i, 255 - ((double)histoGray[i] / maxy*255.0));
				 }
				 lb_histoY->Text = Convert::ToString(maxy);
				
				 break;
			 default:
				 pnDraw->Color = Color::Gray;
				 for (int y = 0; y<imH; y++) {
					 for (int x = 0; x<imW; x++) {
						 gray = arrayGray[y][x];
						 histoGray[gray]++;
					 }//for j
				 }//for i

				 maxy = histoGray[0];
				 for (int i = 0; i < 256; i++) {

					 if (histoGray[i]>maxy) {
						 maxy = histoGray[i];
					 }

				 }

				 for (int i = 0; i < 256; i++) {
					 
					 g->DrawLine(pnDraw, i, 255, i, 255 - ((double)histoGray[i] / maxy*255.0));
				 }
				 lb_histoY->Text = Convert::ToString(maxy);


				 break;

	}
	Pen^ pnDrawT = gcnew Pen(Color::Red);
	g->DrawLine(pnDrawT, T, 0, T, 255);
	lbThresholdVal->Text = Convert::ToString(T);
	lb_histoX->Visible = true;


}
private: System::Void toolStripButtonHistoEq_Click(System::Object^  sender, System::EventArgs^  e) {
	myBitmap = gcnew Bitmap(pictureBoxBefore->ImageLocation);
	Rectangle rect = Rectangle(0, 0, imW, imH);
	BitmapData^ bmpData = myBitmap->LockBits(rect, ImageLockMode::ReadWrite, myBitmap->PixelFormat);
	int ByteOFSkip = bmpData->Stride - bmpData->Width;
	unsigned char* p = (unsigned char*)bmpData->Scan0.ToPointer();
	int index = 0;
	int grayNum[256];
	int gray;
	double pGray[256];
	double fGray[256];
	int sGray[256];

	int rNum[256];
	int red;
	double pR[256];
	double fR[256];
	int sR[256];

	int greenNum[256];
	int green;
	double pG[256];
	double fG[256];
	int sG[256];

	int bNum[256];
	int blue;
	double pB[256];
	double fB[256];
	int sB[256];
	
	if (myBitmap->PixelFormat == PixelFormat::Format24bppRgb) {
		ByteOFSkip = bmpData->Stride - bmpData->Width*3;

		for (int i = 0;i < 256;i++) {
			rNum[i] = 0;
			pR[i] = 0.0;
			fR[i] = 0;
			sR[i] = 0;

			greenNum[i] = 0;
			pG[i] = 0.0;
			fG[i] = 0;
			sG[i] = 0;

			bNum[i] = 0;
			pG[i] = 0.0;
			fG[i] = 0;
			sG[i] = 0;
		}
		for (int y = 0;y < imH;y++) {
			for (int x = 0;x < imW;x++) {

				rNum[arrayR[y][x]] ++;
				greenNum[arrayG[y][x]]++;
				bNum[arrayB[y][x]] ++;
			}
		}
		for (int i = 0;i < 256;i++) {
			pR[i] = (double)rNum[i] / (imW*imH);
			pG[i] = (double)greenNum[i] / (imW*imH);
			pB[i] = (double)bNum[i] / (imW*imH);

		}
		fR[0] = pR[0];
		fG[0] = fG[0];
		fB[0] = pB[0];
		for (int i = 1;i < 256;i++) {
			fR[i] = fR[i - 1] + pR[i];
			fG[i] = fG[i - 1] + pG[i];
			fB[i] = fB[i - 1] + pB[i];
		}
		for (int i = 0;i < 256;i++) {
			sR[i] = round(255 * fR[i]);
			sG[i] = round(255 * fG[i]);
			sB[i] = round(255 * fB[i]);
		}

		for (int y = 0;y < imH;y++) {			for (int x = 0;x < imW;x++) {
				p[index] = sB[arrayB[y][x]];
				p[index+1] = sG[arrayG[y][x]];
				p[index+2] = sR[arrayR[y][x]];
				index += 3;
			}
			index += ByteOFSkip;
		}
	}

	else {
		for (int i = 0;i < 256;i++) {
			grayNum[i] = 0;
			pGray[i] = 0.0;
			fGray[i] = 0;
			sGray[i] = 0;
		}
		for (int y = 0;y < imH;y++) {
			for (int x = 0;x < imW;x++) {

				grayNum[arrayGray[y][x]] ++;
			}
		}
		for (int i = 0;i < 256;i++) {
			pGray[i] = (double)grayNum[i] / (imW*imH);

		}
		fGray[0] = pGray[0];
		for (int i = 1;i < 256;i++) {
			fGray[i] = fGray[i - 1] + pGray[i];
		}
		for (int i = 0;i < 256;i++) {
			sGray[i] = round(255 * fGray[i]);
		}


		for (int y = 0;y < imH;y++) {			for (int x = 0;x < imW;x++) {
				p[index++] = sGray[arrayGray[y][x]];
			}
			index += ByteOFSkip;
		}
	}
	

		
		myBitmap->UnlockBits(bmpData);
		pictureBoxAfter->Image = myBitmap;

		

	


}
private: System::Void toolStripAvFilter_Click(System::Object^  sender, System::EventArgs^  e) {
	double mask_aver3[] = { 1.0 / 9,1.0 / 9,1.0 / 9
		,1.0 / 9, 1.0 / 9, 1.0 / 9
		,1.0 / 9, 1.0 / 9, 1.0 / 9
	};
	double mask_aver5[] = { 1.0 / 25, 1.0 / 25, 1.0 / 25, 1.0 / 25, 1.0 / 25
		, 1.0 / 25, 1.0 / 25, 1.0 / 25, 1.0 / 25, 1.0 / 25
		, 1.0 / 25, 1.0 / 25, 1.0 / 25, 1.0 / 25, 1.0 / 25
		, 1.0 / 25, 1.0 / 25, 1.0 / 25, 1.0 / 25, 1.0 / 25
		, 1.0 / 25, 1.0 / 25, 1.0 / 25, 1.0 / 25, 1.0 / 25
	};
	double mask_aver7[] = { 1.0 / 49, 1.0 / 49, 1.0 / 49, 1.0 / 49, 1.0 / 491.0 / 49, 1.0 / 49
		, 1.0 / 49, 1.0 / 49, 1.0 / 49, 1.0 / 49, 1.0 / 491.0 / 49, 1.0 / 49
		, 1.0 / 49, 1.0 / 49, 1.0 / 49, 1.0 / 49, 1.0 / 491.0 / 49, 1.0 / 49
		, 1.0 / 49, 1.0 / 49, 1.0 / 49, 1.0 / 49, 1.0 / 491.0 / 49, 1.0 / 49
		, 1.0 / 49, 1.0 / 49, 1.0 / 49, 1.0 / 49, 1.0 / 491.0 / 49, 1.0 / 49
		, 1.0 / 49, 1.0 / 49, 1.0 / 49, 1.0 / 49, 1.0 / 491.0 / 49, 1.0 / 49
		, 1.0 / 49, 1.0 / 49, 1.0 / 49, 1.0 / 49, 1.0 / 491.0 / 49, 1.0 / 49
	};
	double mask_aver9[] = { 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81
		, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81
		, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81
		, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81
		, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81
		, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81
		, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81
		, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81
		, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81
	};
	myBitmap = gcnew Bitmap(pictureBoxBefore->ImageLocation);
	double* Mean_Filter = &mask_aver3[0];
	double resultR, resultG, resultB,resultGray, count;
	int c;

	Rectangle rect = Rectangle(0, 0, imW, imH);
	BitmapData^ bmpData = myBitmap->LockBits(rect, ImageLockMode::ReadWrite, myBitmap->PixelFormat);
	int ByteOFSkip = bmpData->Stride - bmpData->Width*3;
	unsigned char* p = (unsigned char*)bmpData->Scan0.ToPointer();

	int index = 0;
	if (radioButton3x3->Checked) {
		maskSize = 3;
		Mean_Filter = &mask_aver3[0];
	}
	else if (radioButton5x5->Checked) {
		maskSize = 5;
		Mean_Filter = &mask_aver5[0];
	}
	else if (radioButton7x7->Checked) {
		maskSize = 7;
		Mean_Filter = &mask_aver7[0];
	}
	else if (radioButton9x9->Checked) {
		maskSize = 9;
		Mean_Filter = &mask_aver9[0];
	}
	c = (maskSize - 1) / 2;
	if (myBitmap->PixelFormat == PixelFormat::Format24bppRgb) {
		for (int y = 0;y < imH;y++) {
			for (int x = 0;x < imW;x++) {
				resultR = 0.0;
				resultG = 0.0;
				resultB = 0.0;
				count = 0.0;
				for (int m = 0;m < maskSize;m++) {
					for (int n = 0;n < maskSize;n++) {
						if ((y - c + m)>=0 && (x - c + n)>=0 && (y - c + m) < imH && (x - c + n) < imW) {
							resultR += (double)arrayR[y - c + m][x - c + n] * Mean_Filter[m*maskSize + n];
							resultG += (double)arrayG[y - c + m][x - c + n] * Mean_Filter[m*maskSize + n];
							resultB += (double)arrayB[y - c + m][x - c + n] * Mean_Filter[m*maskSize + n];
							count += Mean_Filter[m*maskSize + n];
						}

					}
				}
				int r = (int)(resultR / count);
				int g = (int)(resultG / count);
				int b = (int)(resultB / count);
				p[index] = b;
				p[index + 1] = g;
				p[index + 2] = r;
				index += 3;
			}
			index += ByteOFSkip;
		}
	}
	else {
		ByteOFSkip = bmpData->Stride - bmpData->Width;
		for (int y = 0;y < imH;y++) {
			for (int x = 0;x < imW;x++) {
				resultGray = 0.0;
				count = 0.0;
				for (int m = 0;m < maskSize;m++) {
					for (int n = 0;n < maskSize;n++) {
						if ((y - c + m)>=0 && (x - c + n)>=0 && (y - c + m) < imH && (x - c + n) < imW) {
							resultGray += (double)arrayGray[y - c + m][x - c + n] * Mean_Filter[m*maskSize + n];
							
							count += Mean_Filter[m*maskSize + n];
						}

					}
				}
				
				p[index++] = (int)(resultGray/count);
				
			}
			index += ByteOFSkip;
		}
	}

	myBitmap->UnlockBits(bmpData);
	pictureBoxAfter->Image = myBitmap;
}
private: System::Void toolStripButtonSP_Click(System::Object^  sender, System::EventArgs^  e) {
	srand(time(NULL));
	Bitmap^ myBitmap = gcnew Bitmap(pictureBoxBefore->ImageLocation);
	Rectangle rect = Rectangle(0, 0, imW, imH);
	BitmapData^ bmpData = myBitmap->LockBits(rect, ImageLockMode::ReadWrite, myBitmap->PixelFormat);
	int ByteOFSkip = bmpData->Stride - bmpData->Width * 3;
	unsigned char* p = (unsigned char*)bmpData->Scan0.ToPointer();
	double sp;
	sp = Convert::ToDouble(textBoxNoise->Text)*0.01;
	int index = 0;
	if (myBitmap->PixelFormat == PixelFormat::Format24bppRgb) {
		for (int y = 0;y < imH;y++) {
			for (int x = 0;x < imW;x++) {
				double val = (double)rand() / RAND_MAX;
				if (val <= sp / 2.0) {
					p[index] = 255;
					p[index + 1] = 255;
					p[index + 2] = 255;
					index += 3;
				}
				else if (val >= (1 - sp / 2.0)) {
					p[index] = 0;
					p[index + 1] = 0;
					p[index + 2] = 0;
					index += 3;
				}
				else {
					p[index] = arrayB[y][x];
					p[index + 1] = arrayG[y][x];
					p[index + 2] = arrayR[y][x];
					index += 3;
				}

			}
			index += ByteOFSkip;
		}
	}
	else {
		ByteOFSkip = bmpData->Stride - bmpData->Width;
		for (int y = 0;y < imH;y++) {
			for (int x = 0;x < imW;x++) {
				double val = (double)rand() / RAND_MAX;
				if (val <= sp / 2.0) {
					p[index++] = 255;

				}
				else if (val >= (1 - sp / 2.0)) {
					p[index++] = 0;

				}
				else {
					p[index++] = arrayGray[y][x];
				}

			}
			index += ByteOFSkip;
		}
	}
	
	myBitmap->UnlockBits(bmpData);
	pictureBoxAfter->Image = myBitmap;
}
private: System::Void toolStripButton1_Click(System::Object^  sender, System::EventArgs^  e) {
	double mask_gaussian3[9];
	double mask_gaussian5[25];
	double mask_gaussian7[49];
	double mask_gaussian9[81];
	double sigma;
	double resultR, resultG, resultB,resultGray, count;
	sigma = Convert::ToDouble(textBoxSigma->Text);
	int c, r, g, b;
	int index = 0;
	double* Gaussian_Filter = &mask_gaussian3[0];
	Bitmap^ myBitmap = gcnew Bitmap(pictureBoxBefore->ImageLocation);
	Rectangle rect = Rectangle(0, 0, imW, imH);
	BitmapData^ bmpData = myBitmap->LockBits(rect, ImageLockMode::ReadWrite, myBitmap->PixelFormat);
	int ByteOFSkip = bmpData->Stride - bmpData->Width * 3;
	unsigned char* p = (unsigned char*)bmpData->Scan0.ToPointer();
	int i = 0;
	for (int t = -1; t <= 1; t++) {
		for (int s = -1; s <= 1; s++) {
			double exponent = -(s*s + t*t) / (2 * sigma*sigma);
			mask_gaussian3[i++] = exp(exponent);

		}
	}
	i = 0;
	for (int t = -2; t <= 2; t++) {
		for (int s = -2; s <= 2; s++) {
			double exponent = -(s*s + t*t) / (2 * sigma*sigma);
			mask_gaussian5[i++] = exp(exponent);

		}
	}
	i = 0;
	for (int t = -3; t <= 3; t++) {
		for (int s = -3; s <= 3; s++) {
			double exponent = -(s*s + t*t) / (2 * sigma*sigma);
			mask_gaussian7[i++] = exp(exponent);

		}
	}
	i = 0;
	for (int t = -4; t <= 4; t++) {
		for (int s = -4; s <= 4; s++) {
			double exponent = -(s*s + t*t) / (2 * sigma*sigma);
			mask_gaussian9[i++] = exp(exponent);

		}
	}

	if (radioButton3x3->Checked) {
		maskSize = 3;
		Gaussian_Filter = &mask_gaussian3[0];
	}
	else if (radioButton5x5->Checked) {
		maskSize = 5;
		Gaussian_Filter = &mask_gaussian5[0];
	}

	else if (radioButton7x7->Checked) {
		maskSize = 7;
		Gaussian_Filter = &mask_gaussian7[0];
	}
	else if (radioButton9x9->Checked) {
		maskSize = 9;
		Gaussian_Filter = &mask_gaussian9[0];
	}
	c = (maskSize - 1) / 2;
	if (myBitmap->PixelFormat == PixelFormat::Format24bppRgb) {
		for (int y = 0;y < imH;y++) {
			for (int x = 0;x < imW;x++) {
				resultR = 0.0;
				resultG = 0.0;
				resultB = 0.0;
				count = 0.0;
				for (int m = 0;m < maskSize;m++) {
					for (int n = 0;n < maskSize;n++) {
						if ((y - c + m)>=0 && (x - c + n)>=0 && (y - c + m) < imH && (x - c + n) < imW) {
							resultR += (double)arrayR[y - c + m][x - c + n] * Gaussian_Filter[m*maskSize + n];
							resultG += (double)arrayG[y - c + m][x - c + n] * Gaussian_Filter[m*maskSize + n];
							resultB += (double)arrayB[y - c + m][x - c + n] * Gaussian_Filter[m*maskSize + n];
							count += Gaussian_Filter[m*maskSize + n];
						}

					}
				}
				int r = (int)(resultR / count);
				int g = (int)(resultG / count);
				int b = (int)(resultB / count);
				p[index] = b;
				p[index + 1] = g;
				p[index + 2] = r;
				index += 3;
			}
			index += ByteOFSkip;
		}
	}
	else {
		ByteOFSkip = bmpData->Stride - bmpData->Width;
		for (int y = 0;y < imH;y++) {
			for (int x = 0;x < imW;x++) {
				resultGray = 0.0;
				count = 0.0;
				for (int m = 0;m < maskSize;m++) {
					for (int n = 0;n < maskSize;n++) {
						if ((y - c + m)>=0 && (x - c + n)>=0 && (y - c + m) < imH && (x - c + n) < imW) {
							resultGray += (double)arrayGray[y - c + m][x - c + n] * Gaussian_Filter[m*maskSize + n];

							count += Gaussian_Filter[m*maskSize + n];
						}

					}
				}

				p[index++] = (int)(resultGray / count);

			}
			index += ByteOFSkip;
		}
	}

	myBitmap->UnlockBits(bmpData);
	pictureBoxAfter->Image = myBitmap;

}
private: System::Void averageFilterToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	toolStripAvFilter_Click(sender, e);
}
private: System::Void gaussianFilterToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	toolStripButton1_Click(sender, e);
}
private: System::Void histogramEqualizationToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	toolStripButtonHistoEq_Click(sender, e);
}
private: System::Void saltAndPepperNoiseToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	toolStripButtonSP_Click(sender, e);
}
private: System::Void toolStripButtonUnsharp_Click(System::Object^  sender, System::EventArgs^  e) {
	double mask_aver3[] = { 1.0 / 9,1.0 / 9,1.0 / 9
		,1.0 / 9, 1.0 / 9, 1.0 / 9
		,1.0 / 9, 1.0 / 9, 1.0 / 9
	};
	double mask_aver5[] = { 1.0 / 25, 1.0 / 25, 1.0 / 25, 1.0 / 25, 1.0 / 25
		, 1.0 / 25, 1.0 / 25, 1.0 / 25, 1.0 / 25, 1.0 / 25
		, 1.0 / 25, 1.0 / 25, 1.0 / 25, 1.0 / 25, 1.0 / 25
		, 1.0 / 25, 1.0 / 25, 1.0 / 25, 1.0 / 25, 1.0 / 25
		, 1.0 / 25, 1.0 / 25, 1.0 / 25, 1.0 / 25, 1.0 / 25
	};
	double mask_aver7[] = { 1.0 / 49, 1.0 / 49, 1.0 / 49, 1.0 / 49, 1.0 / 491.0 / 49, 1.0 / 49
		, 1.0 / 49, 1.0 / 49, 1.0 / 49, 1.0 / 49, 1.0 / 491.0 / 49, 1.0 / 49
		, 1.0 / 49, 1.0 / 49, 1.0 / 49, 1.0 / 49, 1.0 / 491.0 / 49, 1.0 / 49
		, 1.0 / 49, 1.0 / 49, 1.0 / 49, 1.0 / 49, 1.0 / 491.0 / 49, 1.0 / 49
		, 1.0 / 49, 1.0 / 49, 1.0 / 49, 1.0 / 49, 1.0 / 491.0 / 49, 1.0 / 49
		, 1.0 / 49, 1.0 / 49, 1.0 / 49, 1.0 / 49, 1.0 / 491.0 / 49, 1.0 / 49
		, 1.0 / 49, 1.0 / 49, 1.0 / 49, 1.0 / 49, 1.0 / 491.0 / 49, 1.0 / 49
	};
	double mask_aver9[] = { 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81
		, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81
		, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81
		, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81
		, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81
		, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81
		, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81
		, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81
		, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81, 1.0 / 81
	};
	double resultR, resultG, resultB, resultGray, count;
	int c;
	double* Mean_Filter = &mask_aver3[0];
	double k = 0.0;
	myBitmap = gcnew Bitmap(pictureBoxBefore->ImageLocation);
	Rectangle rect = Rectangle(0, 0, imW, imH);
	BitmapData^ bmpData = myBitmap->LockBits(rect, ImageLockMode::ReadWrite, myBitmap->PixelFormat);
	int ByteOFSkip = bmpData->Stride - bmpData->Width * 3;
	unsigned char* p = (unsigned char*)bmpData->Scan0.ToPointer();

	int index = 0;

	if (radioButton3x3->Checked) {
		maskSize = 3;
		Mean_Filter = &mask_aver3[0];
	}
	else if (radioButton5x5->Checked) {
		maskSize = 5;
		Mean_Filter = &mask_aver5[0];
	}
	else if (radioButton7x7->Checked) {
		maskSize = 7;
		Mean_Filter = &mask_aver7[0];
	}
	else if (radioButton9x9->Checked) {
		maskSize = 9;
		Mean_Filter = &mask_aver9[0];
	}
	
	k=Convert::ToDouble(textBoxSigma->Text);
	if (myBitmap->PixelFormat == PixelFormat::Format24bppRgb) {
		for (int y = 0;y < imH;y++) {
			for (int x = 0;x < imW;x++) {
				resultR = 0.0;
				resultG = 0.0;
				resultB = 0.0;
				count = 0.0;
				for (int m = 0;m < maskSize;m++) {
					for (int n = 0;n < maskSize;n++) {
						if ((y - c + m)>=0 && (x - c + n)>=0 && (y - c + m) < imH && (x - c + n) < imW) {
							resultR += (double)arrayR[y - c + m][x - c + n] * Mean_Filter[m*maskSize + n];
							resultG += (double)arrayG[y - c + m][x - c + n] * Mean_Filter[m*maskSize + n];
							resultB += (double)arrayB[y - c + m][x - c + n] * Mean_Filter[m*maskSize + n];
							count += Mean_Filter[m*maskSize + n];
						}

					}
				}
				int r = arrayR[y][x] +(int)( k*(arrayR[y][x]-(int)(resultR / count)));
				if (r > 255) {
					r = 255;
				}
				else if (r < 0) {
					r = 0;
				}

				int g = arrayG[y][x] + (int)(k*(arrayG[y][x]-(int)(resultG / count)));
				if (g > 255) {
					g = 255;
				}
				else if (g < 0) {
					g = 0;
				}
				int b = arrayB[y][x] + (int)(k*( arrayB[y][x]-(int)(resultB / count)));

				if (b > 255) {
					b = 255;
				}
				else if (b < 0) {
					b = 0;
				}
				
				p[index] = b;
				p[index + 1] = g;
				p[index + 2] = r;
				index += 3;
			}
			index += ByteOFSkip;
		}
		
	}

	else {
		ByteOFSkip = bmpData->Stride - bmpData->Width;
		for (int y = 0;y < imH;y++) {
			for (int x = 0;x < imW;x++) {
				resultGray = 0.0;
				count = 0.0;
				for (int m = 0;m < maskSize;m++) {
					for (int n = 0;n < maskSize;n++) {
						if ((y - c + m)>=0 && (x - c + n)>=0 && (y - c + m) < imH && (x - c + n) < imW) {
							resultGray += (double)arrayGray[y - c + m][x - c + n] * Mean_Filter[m*maskSize + n];

							count += Mean_Filter[m*maskSize + n];
						}

					}
				}

				int gray = arrayGray[y][x] + (int)(k*(arrayGray[y][x] - (int)(resultGray / count)));
				if (gray > 255) {
					gray = 255;
				}
				else if(gray<0){
					gray = 0;
				}
				p[index++] = gray;

			}
			index += ByteOFSkip;
		}
	}

	myBitmap->UnlockBits(bmpData);
	pictureBoxAfter->Image = myBitmap;
}
private: System::Void toolStripButtonMedian_Click(System::Object^  sender, System::EventArgs^  e) {
	double resultR, resultG, resultB, resultGray, count;
	int c;
	myBitmap = gcnew Bitmap(pictureBoxBefore->ImageLocation);
	Rectangle rect = Rectangle(0, 0, imW, imH);
	BitmapData^ bmpData = myBitmap->LockBits(rect, ImageLockMode::ReadWrite, myBitmap->PixelFormat);
	int ByteOFSkip = bmpData->Stride - bmpData->Width * 3;
	unsigned char* p = (unsigned char*)bmpData->Scan0.ToPointer();
	int index = 0;
	int mask_med3[9];
	int mask3R[9];
	int mask3G[9];
	int mask3B[9];
	int mask5R[25];
	int mask5G[25];
	int mask5B[25];
	int mask7R[49];
	int mask7G[49];
	int mask7B[49];
	int mask9R[81];
	int mask9G[81];
	int mask9B[81];
	int mask3Gray[9];
	int mask5Gray[25];
	int mask7Gray[49];
	int mask9Gray[81];
	int r, g, b;
	if (myBitmap->PixelFormat == PixelFormat::Format24bppRgb) {
		if (radioButton3x3->Checked) {
			maskSize = 3;
			c = (maskSize - 1) / 2;
			for (int y = 0;y < imH;y++) {
				for (int x = 0;x < imW;x++) {
					
					int l=0;
				
					
					for (int m = 0;m < maskSize;m++) {
						for (int n = 0;n < maskSize;n++) {
							if ((y - c + m)>=0 && (x - c + n)>=0 && (y - c + m) < imH && (x - c + n) < imW) {
								mask3Gray[l] = arrayGray[y - c + m][x - c + n];
								
								l++;
							}

						}
					}
					std::sort(mask3Gray, mask3Gray + l);
					for (int m = 0;m < maskSize;m++) {
						for (int n = 0;n < maskSize;n++) {
							if ((y - c + m)>=0 && (x - c + n)>=0 && (y - c + m) < imH && (x - c + n) < imW) {
								if (mask3Gray[l / 2] == arrayGray[y - c + m][x - c + n]) {
									p[index] = arrayB[y - c + m][x - c + n];
									p[index + 1] = arrayG[y - c + m][x - c + n];
									p[index + 2] = arrayR[y - c + m][x - c + n];
									index += 3;
									n = maskSize - 1;
									m = maskSize - 1;
								}
							}
						}
					}
					
					
					
					
				}
				index += ByteOFSkip;
			}
		}

		if (radioButton5x5->Checked) {
			maskSize = 5;
			c = (maskSize - 1) / 2;
			for (int y = 0;y < imH;y++) {
				for (int x = 0;x < imW;x++) {

					int l = 0;


					for (int m = 0;m < maskSize;m++) {
						for (int n = 0;n < maskSize;n++) {
							if ((y - c + m) >= 0 && (x - c + n) >= 0 && (y - c + m) < imH && (x - c + n) < imW) {
								mask5Gray[l] = arrayGray[y - c + m][x - c + n];

								l++;
							}

						}
					}
					std::sort(mask5Gray, mask5Gray + l);
					for (int m = 0;m < maskSize;m++) {
						for (int n = 0;n < maskSize;n++) {
							if ((y - c + m) >= 0 && (x - c + n) >= 0 && (y - c + m) < imH && (x - c + n) < imW) {
								if (mask5Gray[l / 2] == arrayGray[y - c + m][x - c + n]) {
									p[index] = arrayB[y - c + m][x - c + n];
									p[index + 1] = arrayG[y - c + m][x - c + n];
									p[index + 2] = arrayR[y - c + m][x - c + n];
									index += 3;
									n = maskSize - 1;
									m = maskSize - 1;
								}
							}
						}
					}




				}
				index += ByteOFSkip;
			}
		}

		if (radioButton7x7->Checked) {
			maskSize = 7;
			c = (maskSize - 1) / 2;
			for (int y = 0;y < imH;y++) {
				for (int x = 0;x < imW;x++) {

					int l = 0;


					for (int m = 0;m < maskSize;m++) {
						for (int n = 0;n < maskSize;n++) {
							if ((y - c + m) >= 0 && (x - c + n) >= 0 && (y - c + m) < imH && (x - c + n) < imW) {
								mask7Gray[l] = arrayGray[y - c + m][x - c + n];

								l++;
							}

						}
					}
					std::sort(mask7Gray, mask7Gray + l);
					for (int m = 0;m < maskSize;m++) {
						for (int n = 0;n < maskSize;n++) {
							if ((y - c + m) >= 0 && (x - c + n) >= 0 && (y - c + m) < imH && (x - c + n) < imW) {
								if (mask7Gray[l / 2] == arrayGray[y - c + m][x - c + n]) {
									p[index] = arrayB[y - c + m][x - c + n];
									p[index + 1] = arrayG[y - c + m][x - c + n];
									p[index + 2] = arrayR[y - c + m][x - c + n];
									index += 3;
									n = maskSize - 1;
									m = maskSize - 1;
								}
							}
						}
					}




				}
				index += ByteOFSkip;
			}
		}

		if (radioButton9x9->Checked) {
			maskSize = 9;
			c = (maskSize - 1) / 2;
			for (int y = 0;y < imH;y++) {
				for (int x = 0;x < imW;x++) {

					int l = 0;


					for (int m = 0;m < maskSize;m++) {
						for (int n = 0;n < maskSize;n++) {
							if ((y - c + m) >= 0 && (x - c + n) >= 0 && (y - c + m) < imH && (x - c + n) < imW) {
								mask9Gray[l] = arrayGray[y - c + m][x - c + n];

								l++;
							}

						}
					}
					std::sort(mask9Gray, mask9Gray + l);
					for (int m = 0;m < maskSize;m++) {
						for (int n = 0;n < maskSize;n++) {
							if ((y - c + m) >= 0 && (x - c + n) >= 0 && (y - c + m) < imH && (x - c + n) < imW) {
								if (mask9Gray[l / 2] == arrayGray[y - c + m][x - c + n]) {
									p[index] = arrayB[y - c + m][x - c + n];
									p[index + 1] = arrayG[y - c + m][x - c + n];
									p[index + 2] = arrayR[y - c + m][x - c + n];
									index += 3;
									n = maskSize - 1;
									m = maskSize - 1;
								}
							}
						}
					}




				}
				index += ByteOFSkip;
			}
		}
	}
	else {
		ByteOFSkip = bmpData->Stride - bmpData->Width;
		if (radioButton3x3->Checked) {


			maskSize = 3;
			c = (maskSize - 1) / 2;
			for (int y = 0;y < imH;y++) {
				for (int x = 0;x < imW;x++) {
					int l = 0;

					for (int m = 0;m < maskSize;m++) {
						for (int n = 0;n < maskSize;n++) {
							if ((y - c + m)>=0 && (x - c + n)>=0 && (y - c + m) < imH && (x - c + n) < imW) {
								mask3Gray[l] = arrayGray[y - c + m][x - c + n];
								l++;
							}

						}
					}
					std::sort(mask3Gray, mask3Gray + l);



					p[index++] = mask3Gray[l / 2];


				}
				index += ByteOFSkip;
			}


		}
		else if (radioButton5x5->Checked) {
			maskSize = 5;
			ByteOFSkip = bmpData->Stride - bmpData->Width;

			c = (maskSize - 1) / 2;
			for (int y = 0;y < imH;y++) {
				for (int x = 0;x < imW;x++) {
					int l = 0;

					for (int m = 0;m < maskSize;m++) {
						for (int n = 0;n < maskSize;n++) {
							if ((y - c + m)>=0 && (x - c + n)>=0 && (y - c + m) < imH && (x - c + n) < imW) {
								mask5Gray[l] = arrayGray[y - c + m][x - c + n];
								l++;
							}

						}
					}
					std::sort(mask5Gray, mask5Gray + l);


					int gray = mask5Gray[l / 2];
					p[index++] = gray;


				}
				index += ByteOFSkip;
			}

		}
		else if (radioButton7x7->Checked) {
			maskSize = 7;

			ByteOFSkip = bmpData->Stride - bmpData->Width;

			c = (maskSize - 1) / 2;
			for (int y = 0;y < imH;y++) {
				for (int x = 0;x < imW;x++) {
					int l = 0;

					for (int m = 0;m < maskSize;m++) {
						for (int n = 0;n < maskSize;n++) {
							if ((y - c + m)>=0 && (x - c + n)>=0 && (y - c + m) < imH && (x - c + n) < imW) {
								mask7Gray[l] = arrayGray[y - c + m][x - c + n];
								l++;
							}

						}
					}
					std::sort(mask7Gray, mask7Gray + l);


					int gray = mask7Gray[l / 2];
					p[index++] = gray;


				}
				index += ByteOFSkip;
			}

		}
		else if (radioButton9x9->Checked) {
			maskSize = 9;
			ByteOFSkip = bmpData->Stride - bmpData->Width;

			c = (maskSize - 1) / 2;
			for (int y = 0;y < imH;y++) {
				for (int x = 0;x < imW;x++) {
					int l = 0;

					for (int m = 0;m < maskSize;m++) {
						for (int n = 0;n < maskSize;n++) {
							if ((y - c + m)>=0 && (x - c + n)>=0 && (y - c + m) < imH && (x - c + n) < imW) {
								mask9Gray[l] = arrayGray[y - c + m][x - c + n];
								l++;
							}

						}
					}
					std::sort(mask9Gray, mask9Gray + l);


					int gray = mask9Gray[l / 2];
					p[index++] = gray;


				}
				index += ByteOFSkip;
			}


		}
	}
	
	myBitmap->UnlockBits(bmpData);
	pictureBoxAfter->Image = myBitmap;
}
private: System::Void hScrollBarT_Scroll(System::Object^  sender, System::Windows::Forms::ScrollEventArgs^  e) {
	T = hScrollBarT->Value;
	lbThresholdVal->Text = Convert::ToString(T);
	comboBoxHistogram_SelectedIndexChanged(sender, e);

}
private: System::Void toolStripButtonbin_Click(System::Object^  sender, System::EventArgs^  e) {
	myBitmap = gcnew Bitmap(pictureBoxBefore->ImageLocation);
	Rectangle rect = Rectangle(0, 0, imW, imH);
	BitmapData^ bmpData = myBitmap->LockBits(rect, ImageLockMode::ReadWrite, myBitmap->PixelFormat);
	int ByteOFSkip = bmpData->Stride - bmpData->Width * 3;
	unsigned char* p = (unsigned char*)bmpData->Scan0.ToPointer();
	int index = 0;
	if (myBitmap->PixelFormat == PixelFormat::Format24bppRgb) {
		for (int y = 0;y < imH;y++) {
			for (int x = 0;x < imW;x++) {
				if (arrayGray[y][x]>T) {
					p[index] = 255;
					p[index + 1] = 255;
					p[index + 2] = 255;
					index += 3;
				}
				else {
					p[index] = 0;
					p[index + 1] = 0;
					p[index + 2] = 0;
					index += 3;
				}
			}
			index += ByteOFSkip;
		}
	}
	else {
		ByteOFSkip = bmpData->Stride - bmpData->Width;
		for (int y = 0;y < imH;y++) {
			for (int x = 0;x < imW;x++) {
				if (arrayGray[y][x]>T) {
					p[index++] = 255;
					
				}
				else {
					p[index++] = 0;
					
				}
			}
			index += ByteOFSkip;
		}
	}
	
	myBitmap->UnlockBits(bmpData);
	pictureBoxAfter->Image = myBitmap;
}
		
private: System::Void toolStripButtonLaplacian_Click(System::Object^  sender, System::EventArgs^  e) {
	double maskLa[] = {
		1.0,1.0,1.0,
		1.0,-8.0,1.0,
		1.0,1.0,1.0
	};
	myBitmap = gcnew Bitmap(pictureBoxBefore->ImageLocation);
	Rectangle rect = Rectangle(0, 0, imW, imH);
	BitmapData^ bmpData = myBitmap->LockBits(rect, ImageLockMode::ReadWrite, myBitmap->PixelFormat);
	int ByteOFSkip = bmpData->Stride - bmpData->Width * 3;
	unsigned char* p = (unsigned char*)bmpData->Scan0.ToPointer();
	
	Bitmap^ myBitmapGray = gcnew Bitmap(imW,imH,PixelFormat::Format8bppIndexed);
		//gray palette
		ColorPalette^ grayP = myBitmapGray->Palette;
		for (int i = 0;i < 256;i++) {
			grayP->Entries[i] = Color::FromArgb(255, i, i, i);
		}
		myBitmapGray->Palette = grayP;
	
	
	BitmapData^ bmpData2 = myBitmapGray->LockBits(rect, ImageLockMode::ReadWrite, myBitmapGray->PixelFormat);
	unsigned char* p2 = (unsigned char*)bmpData2->Scan0.ToPointer();
	int index = 0;
	int index2 = 0;
	double g;
	int c;


	
	maskSize = 3;
	c = (maskSize - 1) / 2;
	double** arrayLa;
	double maxG = 0.0;
	double minG = 999999.0;
	arrayLa = new double*[imH];
	for (int i = 0; i < imH; i++)
		arrayLa[i] = new double[imW];
	bool doFlag;
	if (myBitmap->PixelFormat == PixelFormat::Format24bppRgb) {
		for (int y = 0;y < imH;y++) {
			for (int x = 0;x < imW;x++) {
				g = 0.0;
				doFlag = false;
				for (int m = 0;m < maskSize;m++) {
					for (int n = 0;n < maskSize;n++) {
						if ((y - c + m) >= 0 && (x - c + n) >= 0 && (y - c + m) < imH && (x - c + n) < imW) {
							g += arrayGray[y-c + m][x-c + n] * maskLa[m*maskSize + n];
							doFlag = true;
						}
						
					}//m
				}//n
				if (doFlag) {
					g = abs(g);
					arrayLa[y][x] = g;
					if (g > maxG) {
						maxG = g;
					}
					if (g < minG) {
						minG = g;
					}
				}

				
			}
			
		}
		
		double LS = 255.0 / (maxG - minG);
		int g1=0;
		for (int y = 0;y < imH;y++) {
			for (int x = 0;x < imW;x++) {
				if (y < 1 || x < 1 || y == imH - 1 || x == imW - 1) {
					g1 = 0;
					
				}
				else {
					g1 = (int)(LS * (arrayLa[y][x] - minG));
					
				}
				
				p[index] = g1;
				p[index + 1] = g1;
				p[index + 2] = g1;
				index += 3;
				arrayLa[y][x] = g1;
			}
			index += ByteOFSkip;

		}
		
	}

	else {
		ByteOFSkip = bmpData2->Stride - bmpData2->Width;
		for (int y = 0;y < imH;y++) {
			for (int x = 0;x < imW;x++) {
				g = 0.0;
				doFlag = false;
				for (int m = 0;m < maskSize;m++) {
					for (int n = 0;n < maskSize;n++) {
						if ((y - c + m) >= 0 && (x - c + n) >= 0 && (y - c + m) < imH && (x - c + n) < imW) {
							g += arrayGray[y - c + m][x - c + n] * maskLa[m*maskSize + n];
							doFlag = true;
						}

					}//m
				}//n
				if (doFlag) {
					g = abs(g);
					arrayLa[y][x] = g;
					if (g > maxG) {
						maxG = g;
					}
					if (g < minG) {
						minG = g;
					}
				}


			}

		}

		double LS = 255.0 / (maxG - minG);
		int g1 = 0;
		for (int y = 0;y < imH;y++) {
			for (int x = 0;x < imW;x++) {
				if (y < 1 || x < 1 || y == imH - 1 || x == imW - 1) {
					g1 = 0;

				}
				else {
					g1 = (int)(LS * (arrayLa[y][x] - minG));

				}

				p[index++] = g1;
				
				arrayLa[y][x] = g1;
			}
			index += ByteOFSkip;

		}
	}
	ByteOFSkip = bmpData2->Stride - bmpData2->Width;
	MessageBox::Show(Convert::ToString(minG) + "," + Convert::ToString(maxG) + "," + Convert::ToString(T));
	
	for (int y = 0;y < imH;y++) {
		for (int x = 0;x < imW;x++) {
			
			if (arrayLa[y][x]>T) {
				p2[index2++] = 0;
				
				
			}
			else {
				p2[index2++] = 255;
				
			}
		}
		
		index2 += ByteOFSkip;
	}
	//MessageBox::Show(Convert::ToString(arrayLa[120][50]));
	myBitmap->UnlockBits(bmpData);
	pictureBoxHisto->Image = myBitmap;
	myBitmapGray->UnlockBits(bmpData2);
	pictureBoxAfter->Image = myBitmapGray;
	
}
private: System::Void toolStripButtonOtsu_Click(System::Object^  sender, System::EventArgs^  e) {
	Bitmap^ myBitmapGray = gcnew Bitmap(imW, imH, PixelFormat::Format8bppIndexed);
	Rectangle rect = Rectangle(0, 0, imW, imH);
	//gray palette
	ColorPalette^ grayP = myBitmapGray->Palette;
	for (int i = 0;i < 256;i++) {
		grayP->Entries[i] = Color::FromArgb(255, i, i, i);
	}
	myBitmapGray->Palette = grayP;

	BitmapData^ bmpData2 = myBitmapGray->LockBits(rect, ImageLockMode::ReadWrite, myBitmapGray->PixelFormat);
	unsigned char* p2 = (unsigned char*)bmpData2->Scan0.ToPointer();
	int ByteOFSkip = bmpData2->Stride - bmpData2->Width;
	int index2 = 0;

	
	double arrayP[257];
	double uT = 0.0;
	double maxK = 0.0;
	double w[257];
	double result[257];
	double m[257];
	int Ts = 0;
	double sigmaB = 0.0;
	for (int i = 0;i < 257;i++) {
		arrayP[i] = 0.0;
		w[i] = 0.0;
		m[i] = 0.0;
		result[i] = 0.0;
		
	}
	for (int y = 0;y < imH;y++) {
		for(int x = 0;x < imW;x++ ){
			arrayP[arrayGray[y][x]+1]+=1.0/(imW *imH);
		}
	}
	//MessageBox::Show(Convert::ToString(imW *imH));
	for (int i = 1;i<257;i++) {
		uT = uT + i*arrayP[i];
		//MessageBox::Show(Convert::ToString(arrayP[i]));
	}
	w[0] = 0.0;
	m[0] = 0.0;
	for (int k = 1;k <257;k++) {

		/*
		for (int i = 1;i <= k;i++) {
			wK = wK + arrayP[i];
			mK = mK+i*arrayP[i];
			
		}
		result = pow(uT*wK - mK, 2) / (wK *(1 - wK));
		if (result > maxK) {
			maxK = result;
			T = k-1;
		}*/

		w[k] = w[k - 1] + arrayP[k];
		m[k] = m[k - 1] + 1.0*arrayP[k]*k;
		
		if(w[k]>0)
		
		sigmaB = (uT * w[k] - m[k]) * (uT * w[k] - m[k]) / (w[k] * (1.0 - w[k]));
		
		if (sigmaB > maxK) {
			maxK = sigmaB;
			T = k - 1;
		}
	}
	
	
	for (int y = 0;y < imH;y++) {
		for (int x = 0;x < imW;x++) {

			if (arrayGray[y][x]>T) {
				p2[index2++] = 255;


			}
			else {
				p2[index2++] = 0;

			}
		}

		index2 += ByteOFSkip;
	}
	
	comboBoxHistogram_SelectedIndexChanged(sender, e);
	myBitmapGray->UnlockBits(bmpData2);
	pictureBoxAfter->Image = myBitmapGray;
}
private: System::Void toolStripButtonSobel_Click(System::Object^  sender, System::EventArgs^  e) {
	double maskX[] = {
		-1.0,0.0,1.0,
		-2.0, 0.0, 2.0,
		-1.0,0.0,1.0
	};
	double maskY[] = {
		-1.0,-2.0,-1.0,
		0.0,0.0,0.0,
		1.0,2.0,1.0
	};
	Bitmap^ myBitmapGray2 = gcnew Bitmap(imW, imH, PixelFormat::Format8bppIndexed);
	//gray palette
	ColorPalette^ grayP = myBitmapGray2->Palette;
	for (int i = 0;i < 256;i++) {
		grayP->Entries[i] = Color::FromArgb(255, i, i, i);
	}
	myBitmapGray2->Palette = grayP;

	Rectangle rect = Rectangle(0, 0, imW, imH);
	BitmapData^ bmpData2 = myBitmapGray2->LockBits(rect, ImageLockMode::ReadWrite, myBitmapGray2->PixelFormat);
	unsigned char* p2 = (unsigned char*)bmpData2->Scan0.ToPointer();
	Bitmap^ myBitmapGray3 = gcnew Bitmap(imW, imH, PixelFormat::Format8bppIndexed);
	//gray palette
	
	
	myBitmapGray3->Palette = grayP;


	BitmapData^ bmpData3 = myBitmapGray3->LockBits(rect, ImageLockMode::ReadWrite, myBitmapGray3->PixelFormat);
	unsigned char* p3 = (unsigned char*)bmpData3->Scan0.ToPointer();
	int index2 = 0;
	int index3 = 0;
	double g1,g2;
	int c;

	double maxG = 0.0;
	double minG = 999999.0;

	maskSize = 3;
	c = (maskSize - 1) / 2;
	double** arraySobel;
	
	arraySobel = new double*[imH];
	for (int i = 0; i < imH; i++)
		arraySobel[i] = new double[imW];
	bool doFlag;
	int ByteOFSkip = bmpData2->Stride - bmpData2->Width;

		for (int y = 0;y < imH;y++) {
			for (int x = 0;x < imW;x++) {
				g1 = 0.0;
				g2 = 0.0;
				doFlag = false;
				for (int m = 0;m < maskSize;m++) {
					for (int n = 0;n < maskSize;n++) {
						if ((y - c + m) >= 0 && (x - c + n) >= 0 && (y - c + m) < imH && (x - c + n) < imW) {
							g1 += arrayGray[y - c + m][x - c + n] * maskX[m*maskSize + n];
							g2 += arrayGray[y - c + m][x - c + n] * maskY[m*maskSize + n];
							doFlag = true;
						}

					}//m
				}//n
				if (doFlag) {
					g1 = abs(g1);
					g2 = abs(g2);
					arraySobel[y][x] = g1+g2;
					if (g1+g2 > maxG) {
						maxG = g1+g2;
					}
					if (g1+g2 < minG) {
						minG = g1+g2;
					}
				}


			}

		}

		double LS = 255.0 / (maxG - minG);
		int result = 0;
		for (int y = 0;y < imH;y++) {
			for (int x = 0;x < imW;x++) {
				if (y < 1 || x < 1 || y == imH - 1 || x == imW - 1) {
					result = 0;

				}
				else {
					result = (int)(LS * (arraySobel[y][x] - minG));

				}

				p2[index2 ++] = result;
			}
			index2 += ByteOFSkip;

		}

	

	
	ByteOFSkip = bmpData3->Stride - bmpData3->Width;
	MessageBox::Show(Convert::ToString(minG) + "," + Convert::ToString(maxG) + "," + Convert::ToString(T));

	for (int y = 0;y < imH;y++) {
		for (int x = 0;x < imW;x++) {

			if (arraySobel[y][x]>T) {
				p3[index3++] = 0;


			}
			else {
				p3[index3++] = 255;

			}
		}

		index3 += ByteOFSkip;
	}
	//MessageBox::Show(Convert::ToString(arrayLa[120][50]));
	myBitmapGray2->UnlockBits(bmpData2);
	pictureBoxHisto->Image = myBitmapGray2;
	myBitmapGray3->UnlockBits(bmpData3);
	pictureBoxAfter->Image = myBitmapGray3;
}
private: System::Void toolStripButtonThinning_Click(System::Object^  sender, System::EventArgs^  e) {
	Bitmap^ myBitmapGray2 = gcnew Bitmap(imW, imH, PixelFormat::Format8bppIndexed);
	//gray palette
	ColorPalette^ grayP = myBitmapGray2->Palette;
	for (int i = 0;i < 256;i++) {
		grayP->Entries[i] = Color::FromArgb(255, i, i, i);
	}
	myBitmapGray2->Palette = grayP;

	Rectangle rect = Rectangle(0, 0, imW, imH);
	BitmapData^ bmpData2 = myBitmapGray2->LockBits(rect, ImageLockMode::ReadWrite, myBitmapGray2->PixelFormat);
	unsigned char* p2 = (unsigned char*)bmpData2->Scan0.ToPointer();
	int ByteOFSkip = bmpData2->Stride - bmpData2->Width;
	int index2 = 0;
	bool doChange = true;
	int** arrayThined;
	int z2 = 0;
	int z3 = 0;
	int z4 = 0;
	int z5 = 0;
	int z6 = 0;
	int z7 = 0;
	int z8 = 0;
	int z9 = 0;
	arrayThined = new int*[imH];
	for (int i = 0; i < imH; i++)
		arrayThined[i] = new int[imW];
	for (int y = 0;y < imH;y++) {
		for (int x = 0;x < imW;x++) {
			arrayThined[y][x] = 0;
		}
	}
	int** nZ1;
	nZ1 = new int*[imH];
	for (int i = 0; i < imH; i++)
		nZ1[i] = new int[imW];
	for (int y = 0;y < imH;y++) {
		for (int x = 0;x < imW;x++) {
			nZ1[y][x] = 0;
		}
	}
	int** TZ1;
	TZ1 = new int*[imH];
	for (int i = 0; i < imH; i++)
		TZ1[i] = new int[imW];
	for (int y = 0;y < imH;y++) {
		for (int x = 0;x < imW;x++) {
			TZ1[y][x] = 0;
		}
	}

	int** arrayThined2;
	arrayThined2 = new int*[imH];
	for (int i = 0; i < imH; i++)
		arrayThined2[i] = new int[imW];

	for (int y = 0; y < imH;y++) {
		for (int x = 0; x < imW; x++) {
			if (arrayGray[y][x] == 255) {
				arrayThined[y][x] = 0;
				
			}
			else {
				arrayThined[y][x] = 1;
			}
		}
	}
	while(doChange){
		doChange = false;
		for (int y = 0;y < imH;y++) {
			for (int x = 0;x < imW;x++) {
				arrayThined2[y][x] = arrayThined[y][x];

				
				nZ1[y][x] = 0;
				TZ1[y][x] = 0;
				if (arrayThined[y][x] == 1) {
					for (int m = 0;m < 3;m++) {
						for (int n = 0;n < 3;n++) {
							if ((y - 1 + m) >= 0 && (x - 1 + n) >= 0 && (y - 1 + m) < imH && (x - 1 + n) < imW) {



								z2 = arrayThined[y - 1][x];
								z3 = arrayThined[y - 1][x + 1];
								z4 = arrayThined[y][x + 1];
								z5 = arrayThined[y + 1][x + 1];
								z6 = arrayThined[y + 1][x];
								z7 = arrayThined[y + 1][x - 1];
								z8 = arrayThined[y][x - 1];
								z9 = arrayThined[y - 1][x - 1];
								nZ1[y][x] = z2 + z3 + z4 + z5 + z6 + z7 + z8 + z9;
								if (z2 < z3) {
									TZ1[y][x] ++;
								}
								if (z3 < z4) {
									TZ1[y][x] ++;
								}
								if (z4 < z5) {
									TZ1[y][x] ++;
								}
								if (z5 < z6) {
									TZ1[y][x] ++;
								}
								if (z6 < z7) {
									TZ1[y][x] ++;
								}
								if (z7 < z8) {
									TZ1[y][x] ++;
								}
								if (z8 < z9) {
									TZ1[y][x] ++;
								}
								if (z9 < z2) {
									TZ1[y][x] ++;
								}
								if (nZ1[y][x]>=2 && nZ1[y][x]<=6 && TZ1[y][x] == 1 && (z2*z4*z6) == 0 && (z4*z6*z8) == 0) {
									arrayThined2[y][x] = 0;
									doChange = true;
								}






							}
						}
					}
				}
				
			
				
	}
	
		}
		for (int y = 0;y < imH;y++) {
			for (int x = 0;x < imW;x++) {
				arrayThined[y][x] = arrayThined2[y][x];
			
				nZ1[y][x] = 0;
				TZ1[y][x] = 0;
				if (arrayThined[y][x]==1){
					for (int m = 0;m < 3;m++) {
						for (int n = 0;n < 3;n++) {
							if ((y - 1 + m) >= 0 && (x - 1 + n) >= 0 && (y - 1 + m) < imH && (x - 1 + n) < imW) {


								z2 = arrayThined[y - 1][x];
								z3 = arrayThined[y - 1][x + 1];
								z4 = arrayThined[y][x + 1];
								z5 = arrayThined[y + 1][x + 1];
								z6 = arrayThined[y + 1][x];
								z7 = arrayThined[y + 1][x - 1];
								z8 = arrayThined[y][x - 1];
								z9 = arrayThined[y - 1][x - 1];
								nZ1[y][x] = z2 + z3 + z4 + z5 + z6 + z7 + z8 + z9;
								if (z2 < z3) {
									TZ1[y][x] ++;
								}
								if (z3 < z4) {
									TZ1[y][x] ++;
								}
								if (z4 < z5) {
									TZ1[y][x] ++;
								}
								if (z5 < z6) {
									TZ1[y][x] ++;
								}
								if (z6 < z7) {
									TZ1[y][x] ++;
								}
								if (z7 < z8) {
									TZ1[y][x] ++;
								}
								if (z8 < z9) {
									TZ1[y][x] ++;
								}
								if (z9 < z2) {
									TZ1[y][x] ++;
								}
								if (nZ1[y][x] >= 2 && nZ1[y][x] <= 6 && TZ1[y][x] == 1 && (z2*z4*z8) == 0 && (z2*z6*z8) == 0) {
									arrayThined2[y][x] = 0;
									doChange = true;
								}




							}
						}
					}
				}
				
			}
		}
	}

	for (int y = 0;y < imH;y++) {
		for (int x = 0;x < imW;x++) {

			if (arrayThined2[y][x]==0) {
				p2[index2 ++] = 255;


			}
			else {
				p2[index2 ++] = 0;

			}
		}

		index2 += ByteOFSkip;
	}
	//MessageBox::Show(Convert::ToString(arrayLa[120][50]));
	myBitmapGray2->UnlockBits(bmpData2);
	pictureBoxAfter->Image = myBitmapGray2;
	
}
private: System::Void toolStripButtonRotate_Click(System::Object^  sender, System::EventArgs^  e) {
	int imW2 = (int)(1.414*imW+0.5);
	int imH2 = (int)(1.414 *imH+0.5);
	Bitmap^ myBitmap2 = gcnew Bitmap(imW2,imH2, PixelFormat::Format24bppRgb);
	//gray palette
	

	Rectangle rect = Rectangle(0, 0, imW2, imH2);
	BitmapData^ bmpData2 = myBitmap2->LockBits(rect, ImageLockMode::ReadWrite, myBitmap2->PixelFormat);
	unsigned char* p2 = (unsigned char*)bmpData2->Scan0.ToPointer();
	int ByteOFSkip = bmpData2->Stride - bmpData2->Width *3;
	int index2 = 0;

	double theta=0.0;
	theta = Convert::ToDouble(textBoxRotate->Text);

	int** arrayB2;
	arrayB2 = new int*[imH2];
	for (int i = 0; i < imH2; i++)
		arrayB2[i] = new int[imW2];

	int** arrayG2;
	arrayG2 = new int*[imH2];
	for (int i = 0; i < imH2; i++)
		arrayG2[i] = new int[imW2];

	int** arrayR2;
	arrayR2 = new int*[imH2];
	for (int i = 0; i < imH2; i++)
		arrayR2[i] = new int[imW2];

	int nx, ny, shift_y, shift_x,x1,y1,newX,newY;
	double sin_theta, cos_theta;
	shift_y = imH2 / 2;
	shift_x = imW2 / 2;
	newX = (imW2 - imW) / 2;
	newY = (imH2 - imH) / 2;
	sin_theta = sin(theta);
	cos_theta = cos(theta);
	for (int y2 = 0;y2 < imH2;y2++) {
		for (int x2 = 0;x2 < imW2;x2++) {

			arrayB2[y2][x2] =0;
			arrayG2[y2][x2] = 0;
			arrayR2[y2][x2] = 0;
		}
	}
	for (int y2 = 0;y2 < imH;y2++) {
		for (int x2 = 0;x2 < imW;x2++) {

			arrayB2[y2 + newY][x2 + newX] = arrayB[y2][x2];
			arrayG2[y2 + newY][x2 + newX] = arrayG[y2][x2];
			arrayR2[y2 + newY][x2 + newX] = arrayR[y2][x2];
		}
	}
	for (int y2 = 0;y2 < imH2;y2++) {
		for (int x2 = 0;x2 < imW2;x2++) {
			ny = y2 - shift_y;//shift y
			nx = x2 - shift_x;//shift x
			
			
			y1 = (int)(sin_theta * nx + cos_theta * ny + shift_y);
			x1 = (int)(cos_theta * nx - sin_theta * ny + shift_x);
			if (y1 >= 0 && x1>=0 && x1<imW2 && y1<imH2 ){
				p2[index2] = arrayB2[y1][x1];
				p2[index2 + 1] = arrayG2[y1][x1];
				p2[index2 + 2] = arrayR2[y1][x1];
				
			}
			index2 += 3;
			
		}
		index2 += ByteOFSkip;
		
	}

	
	myBitmap2->UnlockBits(bmpData2);
	pictureBoxAfter->Image = myBitmap2;
}
};
}
