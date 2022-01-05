object Statut_Form: TStatut_Form
  Left = 672
  Top = 334
  BorderStyle = bsNone
  ClientHeight = 123
  ClientWidth = 306
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Statut_Panel: TPanel
    Left = 0
    Top = 0
    Width = 305
    Height = 121
    BevelWidth = 3
    Color = clBlack
    Font.Charset = ARABIC_CHARSET
    Font.Color = clLime
    Font.Height = -16
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    object Statut_Label: TLabel
      Left = 40
      Top = 37
      Width = 152
      Height = 19
      Caption = 'Processing, please wait...'
    end
    object Cancel_SpeedButton: TSpeedButton
      Left = 79
      Top = 61
      Width = 121
      Height = 41
      Cursor = crHandPoint
      Caption = '&Cancel'
      Flat = True
      Font.Charset = ARABIC_CHARSET
      Font.Color = clAqua
      Font.Height = -16
      Font.Name = 'Times New Roman'
      Font.Style = []
      ParentFont = False
      OnClick = Cancel_SpeedButtonClick
    end
  end
end
