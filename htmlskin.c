//
// htmlskin.c
//
// functions to maintain the skin used..
//

#include "common.h"

// definition for the list of files
struct	htmlskin_configList
{
    char *pszIdent;
    char *pszFileName;
    char *pszCSS;
};

struct  htmlskin_configList gstructHTMLSkin[] =
{
    { "A1", "htmlA1.flag", "body { font-family: \"Lucida Console\", Monaco, monospace;\ncolor: black;background-color: white }\n#past { color: #C71585;\nbackground-color: white }\na { font-family: \"Lucida Console\", Monaco, monospace;\nfont-weight: bold;\ntext-decoration: underline;\ncolor: black;\nbackground-color: white }\n" },
    { "A2", "htmlA2.flag", "body { font-family: \"Lucida Console\", Monaco, monospace;\ncolor: white;\nbackground-color: black }\n#past { color: rosybrown;\nbackground-color: black }\na { font-family: \"Lucida Console\", Monaco, monospace;\nfont-weight: bold;\ntext-decoration: underline;\ncolor: #EEE8AA;\nbackground-color: black }\n" },
    { "B1", "htmlB1.flag", "body { font-family: \"Lucida Sans Unicode\", \"Lucida Grande\", sans-serif;\ncolor: black;background-color: white }\n#past { color: #C71585;\nbackground-color: white }\na { font-family: \"Lucida Sans Unicode\", \"Lucida Grande\", sans-serif;\nfont-weight: bold;\ntext-decoration: underline;\ncolor: black;\nbackground-color: white }\n" },
    { "B2", "htmlB2.flag", "body { font-family: \"Lucida Sans Unicode\", \"Lucida Grande\", sans-serif;\ncolor: white;\nbackground-color: black }\n#past { color: rosybrown;\nbackground-color: black }\na { font-family: \"Lucida Sans Unicode\", \"Lucida Grande\", sans-serif;\nfont-weight: bold;\ntext-decoration: underline;\ncolor: #EEE8AA;\nbackground-color: black }\n" },
    { "C1", "htmlC1.flag", "body { font-family: \"Times New Roman\", Times, serif;\ncolor: black;background-color: white }\n#past { color: #C71585;\nbackground-color: white }\na { font-family: \"Times New Roman\", Times, serif;\nfont-weight: bold;\ntext-decoration: underline;\ncolor: black;\nbackground-color: white }\n" },
    { "C2", "htmlC2.flag", "body { font-family: \"Times New Roman\", Times, serif;\ncolor: white;\nbackground-color: black }\n#past { color: rosybrown;\nbackground-color: black }\na { font-family: \"Times New Roman\", Times, serif;\nfont-weight: bold;\ntext-decoration: underline;\ncolor: #EEE8AA;\nbackground-color: black }\n" },
    { NULL, NULL, NULL }
};

int giHTMLSkinOffset = 0;
int giHTMLSkinSize = 0;


//
// function to init the skin system upon startup.
//
void htmlskin_loadStart ()
{
    int iOffset1 = 0;
    int iRet;
    struct stat structStat;

    // first, figure out the size of the array.
    while (1)
    {
        if (gstructHTMLSkin[giHTMLSkinSize].pszIdent == NULL)
            break;

        giHTMLSkinSize++;
    }

    for (iOffset1 = 0; iOffset1 < giHTMLSkinSize; iOffset1++)
    {
        iRet = stat (gstructHTMLSkin[iOffset1].pszFileName, &structStat);

        if (iRet == 0)
        {
            giHTMLSkinOffset = iOffset1;
            break;
        }
    }
}


//
// function to include the current skin into the output stream.
//
int htmlskin_includeCurrentSkin (struct futils_filebuff *pstructFullFile)
{
    return (futils_addStringToFileBufferEnd (gstructHTMLSkin[giHTMLSkinOffset].pszCSS, pstructFullFile));
}


//
// function to set the skin to the defined value.
//
void htmlskin_setSkin (char *szValue)
{
    int iOffset1 = 0;

    // first the delete pass (all of the 0 byte values
    for (iOffset1 = 0; iOffset1 < giHTMLSkinSize; iOffset1++)
    {
        if (gstructHTMLSkin[iOffset1].pszIdent == NULL)
            break;

        _unlink (gstructHTMLSkin[iOffset1].pszFileName);
    }

    // reset to the default..
    giHTMLSkinOffset = 0;

    // now find the matching entry and set it
    for (iOffset1 = 0; iOffset1 < giHTMLSkinSize; iOffset1++)
    {
        if (gstructHTMLSkin[iOffset1].pszIdent == NULL)
            return;

        if (strcmp (szValue, gstructHTMLSkin[iOffset1].pszIdent) == 0)
        {
            giHTMLSkinOffset = iOffset1;
            futils_writeFileHeaderAndData (gstructHTMLSkin[giHTMLSkinOffset].pszFileName, "set", "\n");
        }
    }
}


