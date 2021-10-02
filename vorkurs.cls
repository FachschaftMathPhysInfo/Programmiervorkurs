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
\RequirePackage{needspace}
\RequirePackage{csquotes}
\RequirePackage{graphicx}



%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%% Makefile Helper %%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

\newcommand{\twodigit}[1]{\ifnum\value{#1}<10 0\fi\arabic{#1}}
\newcommand{\dirname}{}
\newcommand{\inputlektion}[1]{\input{kapitel/\dirname/#1}}

\begingroup
\catcode`\^^I=12
\gdef\mytab{^^I}
\endgroup

\newwrite\makefile
\immediate\openout\makefile=helper.mk
\immediate\write\makefile{dir: files/*}
\immediate\write\makefile{\mytab @mkdir vorkurs}

\newcommand{\setdirname}[1]{%
    \renewcommand{\dirname}{#1}
    \immediate\write\makefile{\mytab @echo "Moving files for \dirname"}
    \immediate\write\makefile{\mytab @mkdir vorkurs/\dirname}
}

\newcommand{\registerfile}[1]{
    \immediate\write\makefile{\mytab @cp files/\dirname/#1 vorkurs/\dirname/lektion\twodigit{section}/}
}


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%% Pagestyle Setup %%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

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



%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%% Section/Chapter %%%%%%%
%%%%%%%%%% Formatt %%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

\titleformat{\section}[leftmargin]{}{}{0pt}{}%[\vspace{-5em}]
%\newcommand{\sectionbreak}{\clearpage}
% gehe 42 mm hoch, setzte dort den section Anker und gehe wieder 30 mm runter
\newcommand{\lesson}[1]{%
    \clearpage\vspace*{-42mm} \section{#1} \vspace*{30mm}
    \renewcommand{\myrightmark}{#1}
    \immediate\write\makefile{\mytab @mkdir vorkurs/\dirname/lektion\twodigit{section}}
}
%\newcommand{\lesson}[1]{\section{#1}\vspace{5em}\markright{#1}}
\renewcommand*\thesection{\arabic{section}}
\newenvironment{praxis}[1][\unskip]{\Needspace{4\baselineskip}\textbf{Praxis: #1}}{\pagebreak[0]}
\newenvironment{spiel}[1][\unskip]{\Needspace{4\baselineskip}\textbf{Spiel: #1}}{\pagebreak[0]}

\titlecontents{chapter}[0pt]{\vspace{1em}\large}{\makebox[60pt][l]{\textbf{Kapitel \thecontentslabel:}}\hspace*{10pt}}{}{\titlerule*[1pc]{ }\contentspage}
\titlecontents{section}[10pt]{}{\makebox[50pt][l]{Lektion \thecontentslabel:}\hspace*{10pt}}{}{\titlerule*[1pc]{ }\contentspage}




%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%% Cpp-Commands %%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

\newcommand{\inputcpp}[1]{\usemintedstyle{vs}\inputminted[label=#1,linenos=true,frame=single]{c++}{files/\dirname/#1}}
\newcommand{\inputshell}[1]{\usemintedstyle{vs}\inputminted[label=#1,linenos=true,frame=single]{bash}{files/\dirname/#1}}
\newcommand{\cppsect}[3]{\usemintedstyle{vs}\inputminted[label=#1,linenos=true,frame=single,firstline=#2,lastline=#3,firstnumber=#2]{c++}{files/\dirname/#1}}
\newcommand{\cppinline}[1]{\usemintedstyle{vs}\mintinline[breaklines]{c++}{#1}}

\newminted{text}{frame=single}
