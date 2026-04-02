// wxWidgets "Hello World" Program

// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#include <mathplot.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class MyApp : public wxApp
{
	public:
		virtual bool OnInit();
};

class MyFrame : public wxFrame
{
	public:
		MyFrame();

	private:
		void OnHello(wxCommandEvent& event);
		void OnExit(wxCommandEvent& event);
		void OnAbout(wxCommandEvent& event);
		struct {
			mpScaleX* AxisX;
			mpScaleY* AxisY;
			mpWindow* Plot;
			mpFXYVector* Vector;
			mpInfoCoords * InfoCoors;
		} sPlot[4];
};

enum
{
	ID_Hello = 1
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
	MyFrame *frame = new MyFrame();
	frame->Show(true);
	return true;
}

MyFrame::MyFrame()
	: wxFrame(NULL, wxID_ANY, "Hello World")
{
	wxMenu *menuFile = new wxMenu;
	menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
			"Help string shown in status bar for this menu item");
	menuFile->AppendSeparator();
	menuFile->Append(wxID_EXIT);

	wxMenu *menuHelp = new wxMenu;
	menuHelp->Append(wxID_ABOUT);

	wxMenuBar *menuBar = new wxMenuBar;
	menuBar->Append(menuFile, "&File");
	menuBar->Append(menuHelp, "&Help");

	SetMenuBar( menuBar );

	CreateStatusBar();
	SetStatusText("Welcome to wxWidgets!");

	Bind(wxEVT_MENU, &MyFrame::OnHello, this, ID_Hello);
	Bind(wxEVT_MENU, &MyFrame::OnAbout, this, wxID_ABOUT);
	Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);
	//wxBoxSizer * topsizer=new wxBoxSizer(wxVERTICAL);
	wxGridSizer * topsizer=new wxGridSizer(2,2,0,0);
	for(size_t i=0;i<4;i++)
	{
		sPlot[i].Plot = new mpWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
		wxMenu * mnu = sPlot[i].Plot->GetPopupMenu();
		mnu->Delete(mpID_LOAD_FILE);
		mnu->Delete(mpID_TOGGLE_COORD);
		mnu->Delete(mpID_TOGGLE_GRID);
		mnu->Delete(mpID_FULLSCREEN);
		mnu->Delete(mpID_SCREENSHOT);
		mnu->Delete(mpID_LOCKASPECT);
		sPlot[i].Plot->SetMargins(10,10,30,10);
		topsizer->Add( sPlot[i].Plot, 1, wxALL|wxEXPAND, 5 );
		sPlot[i].AxisX = new mpScaleX(_("F"), mpALIGN_BOTTOM, true);
		sPlot[i].Plot->AddLayer(sPlot[i].AxisX);
		sPlot[i].AxisY = new mpScaleY(_("?"), mpALIGN_LEFT, true);
		sPlot[i].Plot->AddLayer(sPlot[i].AxisY);
		sPlot[i].Vector = new mpFXYVector(_("Vector"), 0);
		sPlot[i].Vector->SetContinuity(true);
		sPlot[i].Vector->SetPen(wxPen(*wxBLUE));
		sPlot[i].Plot->AddLayer(sPlot[i].Vector);
		sPlot[i].InfoCoors = new mpInfoCoords();
		sPlot[i].Plot->AddLayer(sPlot[i].InfoCoors);
		sPlot[i].Plot->UpdateAll();
		sPlot[i].Plot->Fit();
	}
	std::vector<double> X; std::vector<double> Y;
	X = {0,1}; Y= {0, 1};
	sPlot[0].Vector->SetData(X, Y);
	X = {0,1}; Y= {0, 1e308};
	sPlot[1].Vector->SetData(X, Y);
	X = {0,1}; Y= {0, 1e-308};
	sPlot[2].Vector->SetData(X, Y);
	X = {0,1}; Y= {0, 1e-10};
	sPlot[3].Vector->SetData(X, Y);
	for(size_t i=0;i<4;i++)
		sPlot[i].Plot->Fit();
	SetSizer(topsizer);
}

void MyFrame::OnExit(wxCommandEvent& event)
{
	(void)event;
	Close(true);
}

void MyFrame::OnAbout(wxCommandEvent& event)
{
	(void)event;
	wxMessageBox("This is a wxWidgets Hello World example",
			"About Hello World", wxOK | wxICON_INFORMATION);
}

void MyFrame::OnHello(wxCommandEvent& event)
{
	(void)event;
	wxLogMessage("Hello world from wxWidgets!");
}

