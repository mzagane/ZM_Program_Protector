object Main_Form: TMain_Form
  Left = 785
  Top = 325
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'ZM Programs Protector'
  ClientHeight = 263
  ClientWidth = 351
  Color = clBlack
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Rename_SpeedButton: TSpeedButton
    Left = 8
    Top = 184
    Width = 105
    Height = 33
    Caption = '&Rename'
    Flat = True
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clAqua
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    OnClick = Rename_SpeedButtonClick
  end
  object Restor_SpeedButton: TSpeedButton
    Left = 125
    Top = 184
    Width = 105
    Height = 33
    Caption = 'Res&tor'
    Flat = True
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clAqua
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    OnClick = Restor_SpeedButtonClick
  end
  object Quit_SpeedButton: TSpeedButton
    Left = 241
    Top = 184
    Width = 100
    Height = 33
    Caption = 'Quit'
    Flat = True
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clAqua
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    OnClick = Quit_SpeedButtonClick
  end
  object About_Label: TLabel
    Left = 144
    Top = 232
    Width = 56
    Height = 18
    Cursor = crHandPoint
    Caption = 'About...'
    Font.Charset = ANSI_CHARSET
    Font.Color = clAqua
    Font.Height = -16
    Font.Name = 'Monotype Corsiva'
    Font.Style = [fsBold, fsItalic, fsUnderline]
    ParentFont = False
    OnClick = About_LabelClick
  end
  object Main_PageControl: TPageControl
    Left = 8
    Top = 8
    Width = 333
    Height = 169
    ActivePage = Dir_TabSheet
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clLime
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    MultiLine = True
    ParentFont = False
    ParentShowHint = False
    ScrollOpposite = True
    ShowHint = True
    TabIndex = 0
    TabOrder = 0
    object Dir_TabSheet: TTabSheet
      Hint = 'S'#233'lection de repertoire de base '
      Caption = '&Directory'
      object GroupBox1: TGroupBox
        Left = 2
        Top = -1
        Width = 321
        Height = 134
        TabOrder = 0
        object Dir_Label: TLabel
          Left = 8
          Top = 16
          Width = 75
          Height = 13
          Caption = 'Base Directory :'
        end
        object Brows_SpeedButton: TSpeedButton
          Left = 219
          Top = 66
          Width = 81
          Height = 29
          Caption = '&Browse...'
          Flat = True
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clAqua
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          OnClick = Brows_SpeedButtonClick
        end
        object Basic_Dir_Edit: TEdit
          Left = 7
          Top = 36
          Width = 291
          Height = 21
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clNavy
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = []
          ParentFont = False
          TabOrder = 0
        end
      end
    end
    object Extension_TabSheet: TTabSheet
      Hint = 'S'#233'lectionner ici les types de fichiers que vous voulez prot'#233'ger'
      Caption = '&Extension'
      ImageIndex = 1
      object GroupBox2: TGroupBox
        Left = 5
        Top = -1
        Width = 318
        Height = 138
        TabOrder = 0
        object Extension_CheckListBox: TCheckListBox
          Left = 8
          Top = 16
          Width = 81
          Height = 114
          Color = clBlack
          ItemHeight = 13
          Items.Strings = (
            'exe'
            'com'
            'bat'
            'dll'
            'ocx'
            'cpl'
            'html'
            'htm'
            'bmp'
            'jpg'
            'gif'
            'mpg'
            'avi'
            'wmv'
            'zip'
            'rar'
            'doc'
            'docx'
            'xls'
            'xlsx'
            'ppt'
            'pptx')
          TabOrder = 0
        end
        object GroupBox3: TGroupBox
          Left = 98
          Top = 12
          Width = 212
          Height = 117
          Caption = 'Add an extension : '
          TabOrder = 1
          object Add_SpeedButton: TSpeedButton
            Left = 115
            Top = 80
            Width = 86
            Height = 27
            Caption = '&Add'
            Flat = True
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clAqua
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            OnClick = Add_SpeedButtonClick
          end
          object New_Extension_Label: TLabel
            Left = 8
            Top = 18
            Width = 196
            Height = 13
            Caption = 'New extension (without '#39'.'#39' example : zm) : '
          end
          object New_Extension_Edit: TEdit
            Left = 8
            Top = 44
            Width = 193
            Height = 21
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clNavy
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = []
            ParentFont = False
            TabOrder = 0
          end
        end
      end
    end
    object Options_TabSheet: TTabSheet
      Hint = 'Configuration de traitement'
      Caption = '&Options'
      ImageIndex = 2
      object String_To_Add_Label: TLabel
        Left = 8
        Top = 16
        Width = 129
        Height = 13
        Caption = 'String to add to extension : '
      end
      object String_To_Add_Edit: TEdit
        Left = 162
        Top = 18
        Width = 83
        Height = 22
        BevelInner = bvNone
        BevelOuter = bvNone
        BorderStyle = bsNone
        Color = clBlack
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clYellow
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        Text = 'ZMPP'
      end
      object Sub_Dirs_CheckBox: TCheckBox
        Left = 8
        Top = 56
        Width = 161
        Height = 17
        Caption = 'Include the sub-directory'
        Checked = True
        State = cbChecked
        TabOrder = 1
      end
    end
    object Help_TabSheet: TTabSheet
      Caption = '&Help'
      ImageIndex = 3
      object Label1: TLabel
        Left = 104
        Top = 107
        Width = 56
        Height = 18
        Cursor = crHandPoint
        Caption = 'About...'
        Font.Charset = ANSI_CHARSET
        Font.Color = clYellow
        Font.Height = -16
        Font.Name = 'Monotype Corsiva'
        Font.Style = [fsBold, fsItalic, fsUnderline]
        ParentFont = False
        OnClick = About_LabelClick
      end
      object Memo1: TMemo
        Left = 0
        Top = 8
        Width = 321
        Height = 89
        Color = cl3DDkShadow
        Lines.Strings = (
          'Often, the viruses infect the programs file i.e. which have '
          'extensions (exe, COM, DLL, ocx...). And others virus (macros '
          
            'virus) infect the HTML file,  images... to protect your  files a' +
            'nd '
          'especially when you are obliged to connect your USB key to '
          'infected computer, or if you want to share a directory in a '
          'network, there is  an idea consists to rename your files by '
          
            'adding a string to the extensions  has fine to change their type' +
            's '
          '(*.exe --> exedd,  html --> htmlff) and after you removes the '
          'added  chains and thus restores their types.  But that becomes '
          
            'tiresome if there are many files to rename and especially if you' +
            ' '
          'classified them in sub-directory.  To automate the operation '
          '(rename / restore), I programmed ZM Programs Protector.  With '
          'ZM Programs Protector it is enough to indicate the basic '
          'directory where your files exist and the files types to be '
          'protected and it do the remainder.  ')
        ReadOnly = True
        ScrollBars = ssVertical
        TabOrder = 0
      end
    end
  end
end
