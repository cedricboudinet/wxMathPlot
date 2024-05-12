/***************************************************************
 * Name:      MathPlotConfig.h
 * Purpose:   Defines Application Frame
 * Author:    Lionel ()
 * Created:   2021-01-24
 * Copyright: Lionel ()
 * License:
 **************************************************************/

#ifndef MATHPLOTCONFIGMAIN_H
#define MATHPLOTCONFIGMAIN_H

#include "mathplot.h"

//(*Headers(MathPlotConfigDialog)
#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/choice.h>
#include <wx/dialog.h>
#include <wx/notebook.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/spinctrl.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

#include <wx/colordlg.h>
#include <wx/fontdlg.h>
#include <wx/valnum.h>

// MathPlot namespace
namespace MathPlot
{

class WXDLLIMPEXP_MATHPLOT mpWindow;
class WXDLLIMPEXP_MATHPLOT mpLayer;
class WXDLLIMPEXP_MATHPLOT mpFunction;
class WXDLLIMPEXP_MATHPLOT mpInfoCoords;
class WXDLLIMPEXP_MATHPLOT mpInfoLegend;
class WXDLLIMPEXP_MATHPLOT mpScale;
class WXDLLIMPEXP_MATHPLOT mpText;

class MathPlotConfigDialog: public wxDialog
{
  public:

    MathPlotConfigDialog(wxWindow *parent, wxWindowID id = -1);
    virtual ~MathPlotConfigDialog();

    void Initialize();

  private:

    mpWindow* m_plot;
    mpText* CurrentTitle;
    mpInfoLegend* CurrentLegend;
    mpInfoCoords* CurrentCoords;
    mpScale* CurrentScale;
    mpFunction* CurrentSerie;
    wxButton* colourButton;
    wxChoice* CurrentChoice;
    bool fontTitleChanged;
    bool fontLegendChanged;
    bool fontAxisChanged;
    unsigned int int_top, int_bottom, int_left, int_right;
    int scale_offset;
    double scale_min, scale_max;
    bool CheckBar;

    //(*Handlers(MathPlotConfigDialog)
    void OnQuit(wxCommandEvent &event);
    void OnnbConfigPageChanged(wxNotebookEvent &event);
    void OnbColorClick(wxCommandEvent &event);
    void OnChoiceSeries(wxCommandEvent &event);
    void OnAxisSelect(wxCommandEvent &event);
    void OncbFormatSelect(wxCommandEvent &event);
    void OncbAutoScaleClick(wxCommandEvent &event);
    void OnbApplyClick(wxCommandEvent &event);
    void OnbFontClick(wxCommandEvent &event);
    void OnbDelSeriesClick(wxCommandEvent &event);
    //*)

    //(*Identifiers(MathPlotConfigDialog)
    //*)

    //(*Declarations(MathPlotConfigDialog)
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* sizerMain;
    wxButton* bApply;
    wxButton* bAxisPenColor;
    wxButton* bBGColor;
    wxButton* bClose;
    wxButton* bCoordBrushColor;
    wxButton* bDelSeries;
    wxButton* bFontAxis;
    wxButton* bFontLegend;
    wxButton* bFontTitle;
    wxButton* bLegendBrushColor;
    wxButton* bSeriesBrushColor;
    wxButton* bSeriesPenColor;
    wxCheckBox* cbAutoScale;
    wxCheckBox* cbAxisOutside;
    wxCheckBox* cbAxisVisible;
    wxCheckBox* cbBar;
    wxCheckBox* cbCoordVisible;
    wxCheckBox* cbCoordinates;
    wxCheckBox* cbDrawBox;
    wxCheckBox* cbIsY2Axis;
    wxCheckBox* cbLegendVisible;
    wxCheckBox* cbLogAxis;
    wxCheckBox* cbMagnetize;
    wxCheckBox* cbSecondYAxis;
    wxCheckBox* cbSeriesContinuity;
    wxCheckBox* cbSeriesOutside;
    wxCheckBox* cbSeriesShowName;
    wxCheckBox* cbSeriesVisible;
    wxCheckBox* cbTitleVisible;
    wxCheckBox* cbTractable;
    wxChoice* ChoiceAxis;
    wxChoice* ChoiceSeries;
    wxChoice* cbAxisPenStyle;
    wxChoice* cbAxisPenWidth;
    wxChoice* cbAxisPosition;
    wxChoice* cbCoord;
    wxChoice* cbCoordBrushStyle;
    wxChoice* cbFormat;
    wxChoice* cbLegendBrushStyle;
    wxChoice* cbLegendDirection;
    wxChoice* cbLegendPosition;
    wxChoice* cbLegendStyle;
    wxChoice* cbSeriesBrushStyle;
    wxChoice* cbSeriesPenStyle;
    wxChoice* cbSeriesPenWidth;
    wxChoice* cbSeriesSymbolType;
    wxNotebook* nbConfig;
    wxPanel* Panel1;
    wxPanel* Panel2;
    wxPanel* Panel3;
    wxPanel* Panel4;
    wxSpinCtrl* cbSeriesStep;
    wxSpinCtrl* cbSeriesSymbolSize;
    wxStaticText* StaticText10;
    wxStaticText* StaticText11;
    wxStaticText* StaticText12;
    wxStaticText* StaticText13;
    wxStaticText* StaticText14;
    wxStaticText* StaticText15;
    wxStaticText* StaticText16;
    wxStaticText* StaticText17;
    wxStaticText* StaticText18;
    wxStaticText* StaticText19;
    wxStaticText* StaticText1;
    wxStaticText* StaticText20;
    wxStaticText* StaticText21;
    wxStaticText* StaticText22;
    wxStaticText* StaticText23;
    wxStaticText* StaticText24;
    wxStaticText* StaticText25;
    wxStaticText* StaticText26;
    wxStaticText* StaticText27;
    wxStaticText* StaticText28;
    wxStaticText* StaticText29;
    wxStaticText* StaticText2;
    wxStaticText* StaticText3;
    wxStaticText* StaticText4;
    wxStaticText* StaticText5;
    wxStaticText* StaticText6;
    wxStaticText* StaticText7;
    wxStaticText* StaticText8;
    wxStaticText* StaticText9;
    wxTextCtrl* edAxisName;
    wxTextCtrl* edFormat;
    wxTextCtrl* edMarginBottom;
    wxTextCtrl* edMarginLeft;
    wxTextCtrl* edMarginRight;
    wxTextCtrl* edMarginTop;
    wxTextCtrl* edScaleMax;
    wxTextCtrl* edScaleMin;
    wxTextCtrl* edSeriesName;
    wxTextCtrl* edTitle;
    //*)

    void UpdateSelectedSerie(void);
    void UpdateAxis(void);

    void DoApplyColour(const wxColour &colour);
    void UpdateFont(mpLayer *layer, wxButton *button, bool get_set);
    void SetFontChildren(wxButton *p, const wxFontData &fontdata);

    wxBrushStyle IdToBrushStyle(int id);
    int BrushStyleToId(wxBrushStyle style);

  DECLARE_EVENT_TABLE()
};

} // MathPlot namespace

#endif // MATHPLOTCONFIGMAIN_H

