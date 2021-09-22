\NeedsTeXFormat{LaTeX2e}
\ProvidesClass{vorkurs}[2012/06/08 MathPhysInfo Info-vorkurs]

\DeclareOption*{\PassOptionsToClass{\CurrentOption}{scrbook}}
\ProcessOptions\relax
\LoadClass[a4paper,oneside,headings=optiontohead]{scrbook}

\RequirePackage{fancyhdr}
\RequirePackage[explicit,clearempty]{titlesec}
\RequirePackage{titletoc}
\RequirePackage{amsmath}
\RequirePackage{mathtools}
\RequirePackage[ngerman]{babel}
\RequirePackage{microtype}
\RequirePackage{minted}

%\setcounter{secnumdepth}{-1}
\pagestyle{fancy}
\setlength{\parskip}{0.5em}
\setlength{\parindent}{0pt}
\addtolength{\headheight}{\baselineskip}
%\renewcommand{\sectionmark}[1]{\markright{#1}}
\newcommand{\myrightmark}{bar}
\renewcommand{\sectionmark}[1]{\renewcommand{\myrightmark}{batz}}
\renewcommand{\chaptermark}[1]{\renewcommand{\leftmark}{#1}}
\lhead{\textsc{\leftmark}}
%\chead{\small{Programmiervorkurs der Fachschaft MathPhysInfo} \\ \vspace{0.5em}\textbf{\large Lektion \thesection: \rightmark}}
\chead{\small{Programmiervorkurs der Fachschaft MathPhysInfo} \\ \vspace{0.5em}\textbf{\large Lektion \thesection: \myrightmark}}
\rhead{\small Seite \thepage}
\lfoot{}
\cfoot{}
\rfoot{}

\titleformat{\section}[leftmargin]{}{}{0pt}{}%[\vspace{-5em}]
%\newcommand{\sectionbreak}{\clearpage}
% gehe 42 mm hoch, setzte dort den section Anker und gehe wieder 30 mm runter
\newcommand{\lesson}[1]{\clearpage\vspace*{-42mm} \section{#1} \vspace*{30mm}\renewcommand{\myrightmark}{#1}}
%\newcommand{\lesson}[1]{\section{#1}\vspace{5em}\markright{#1}}
\renewcommand*\thesection{\arabic{section}}

\titlecontents{chapter}[0pt]{\vspace{1em}\large}{\makebox[60pt][l]{\textbf{Kapitel \thecontentslabel:}}\hspace*{10pt}}{}{\titlerule*[1pc]{ }\contentspage}
\titlecontents{section}[10pt]{}{\makebox[50pt][l]{Lektion \thecontentslabel:}\hspace*{10pt}}{}{\titlerule*[1pc]{ }\contentspage}

\newcommand{\inputcpp}[1]{\usemintedstyle{vs}\inputminted[label=#1,linenos=true,frame=single]{c++}{files/#1}}
\newcommand{\inputshell}[1]{\usemintedstyle{vs}\inputminted[label=#1,linenos=true,frame=single]{bash}{files/#1}}
\newcommand{\cppsect}[3]{\usemintedstyle{vs}\inputminted[label=#1,linenos=true,frame=single,firstline=#2,lastline=#3,firstnumber=#2]{c++}{files/#1}}
\newcommand{\cppinline}[1]{\usemintedstyle{vs}\mintinline{c++}{#1}}

\newminted{text}{frame=single}
