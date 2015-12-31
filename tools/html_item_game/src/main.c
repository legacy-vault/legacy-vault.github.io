// Legacy Vault
// html_item_game
// main.c
// Version 1.3

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "main.h"
#include "const.h"
#include "str.h"

int main(int argc, char* argv[])
{
    // DEFINITION //////////////////////////////////////////////////////////////
    // Strings
    char128 groups[groupsN]; // Array of char128, contains Names of Groups
    char128 groupIcons[groupsN];
    char128 properties[propertiesN]; // Array of char128, contains Names of Properties
    char128 propertyIcons[propertiesN];
    char128 game_title;
    char128 propertiesFPs[propertiesN]; // Paths to Properties's Files (1.txt, 2.txt, ...)
    line propertiesData[propertiesN];
    char titleFP[sizeof(char128)];
    char groupsFP[sizeof(char128)];
    char groupIconsFP[sizeof(char128)];
    char propertiesFP[sizeof(char128)];
    char propertyIconsFP[sizeof(char128)];
    char outFP_t[sizeof(char128)];
    char outFP_g[sizeof(char128)];
    char tmp_char[sizeof(char128)];

    // INIT ////////////////////////////////////////////////////////////////////
    // Strings
    char *path_cfg = argv[1];
    char *path_out = argv[2];
    memset(titleFP,'\0',sizeof(titleFP));
    memset(groupsFP,'\0',sizeof(groupsFP));
    memset(groupIconsFP,'\0',sizeof(groupsFP));
    memset(propertiesFP,'\0',sizeof(propertiesFP));
    memset(propertyIconsFP,'\0',sizeof(groupsFP));
    memset(outFP_t,'\0',sizeof(outFP_t));
    memset(outFP_g,'\0',sizeof(outFP_g));
    memset(tmp_char,'\0',sizeof(tmp_char));
    bool blue = true;

	// Intro
	//printf("Welcome to %s version %s.\r\n", tool_name, tool_version);

    // Check Command Line Parameters ///////////////////////////////////////////
    if (argc == 3)
    {
        ;
    }
    else
    {
        printf("Usage: html_item_game cfg_path out_path.\n\n");
        return 1;
    }

    // Reading Configuration from Files ////////////////////////////////////////
    printf("Configuration folder = [%s]\n", path_cfg);//dbg

    // 1. Read Title
    char *ptr = NULL;
    ptr = createPath (titleFP, sizeof(titleFP), path_cfg, sep, titleFN);
    if ((fp = fopen(ptr, "rt"))==NULL)
    {
        printf("Can not open file [%s].\n", ptr);
        return 1;
    }
    // Filtering \r & \n
    fgets(tmp_char, sizeof(game_title.text), fp);
    j = 0; j_max = strlen(tmp_char) - 1; k = 0;
    while (j <= j_max)
    {
        c = tmp_char[j];
        if ((c != '\r') && (c != '\n'))
        {
            game_title.text[k] = c;
            k++;
        }
        j++;
    }
    game_title.text[k] = '\0';
    OK = 1; OK = fclose(fp);
    if (OK != 0)
    {
        printf("Can not close file [%s].\n", ptr);
        return 1;
    }

    // 2. Read Groups
    ptr = NULL;
    ptr = createPath (groupsFP, sizeof(groupsFP), path_cfg, sep, groupsFN);
    if ((fp = fopen(ptr, "rt"))==NULL)
    {
        printf("Can not open file [%s].\n", ptr);
        return 1;
    }
    // Filtering \r & \n
    for (i=1;i<=groupsN;i++)
    {
        fgets(tmp_char, sizeof(groups[i-1]), fp);
        j = 0; j_max = strlen(tmp_char) - 1; k = 0;
        while (j <= j_max)
        {
            c = tmp_char[j];
            if ((c != '\r') && (c != '\n'))
            {
                groups[i-1].text[k] = c;
                k++;
            }
            j++;
        }
        groups[i-1].text[k] = '\0';
    }
    OK = 1; OK = fclose(fp);
    if (OK != 0)
    {
        printf("Can not close file [%s].\n", ptr);
        return 1;
    }

    // 2. Read Group Icons
    ptr = NULL;
    ptr = createPath (groupIconsFP, sizeof(groupIconsFP), path_cfg, sep, groupIconsFN);
    if ((fp = fopen(ptr, "rt"))==NULL)
    {
        printf("Can not open file [%s].\n", ptr);
        return 1;
    }
    // Filtering \r & \n
    for (i=1;i<=groupsN;i++)
    {
        fgets(tmp_char, sizeof(groupIcons[i-1]), fp);
        j = 0; j_max = strlen(tmp_char) - 1; k = 0;
        while (j <= j_max)
        {
            c = tmp_char[j];
            if ((c != '\r') && (c != '\n'))
            {
                groupIcons[i-1].text[k] = c;
                k++;
            }
            j++;
        }
        groupIcons[i-1].text[k] = '\0';
    }
    OK = 1; OK = fclose(fp);
    if (OK != 0)
    {
        printf("Can not close file [%s].\n", ptr);
        return 1;
    }

    // 3. Read Properties
    ptr = NULL;
    ptr = createPath (propertiesFP, sizeof(propertiesFP), path_cfg, sep, propertiesFN);
    if ((fp = fopen(ptr, "rt"))==NULL)
    {
        printf("Can not open file [%s].\n", ptr);
        return 1;
    }
    // Filtering \r & \n
    for (i=1;i<=propertiesN;i++)
    {
        fgets(tmp_char, sizeof(properties[i-1]), fp);
        j = 0; j_max = strlen(tmp_char) - 1; k = 0;
        while (j <= j_max)
        {
            c = tmp_char[j];
            if ((c != '\r') && (c != '\n'))
            {
                properties[i-1].text[k] = c;
                k++;
            }
            j++;
        }
        properties[i-1].text[k] = '\0';
    }
    OK = 1; OK = fclose(fp);
    if (OK != 0)
    {
        printf("Can not close file [%s].\n", ptr);
        return 1;
    }

    // 4. Read Property Icons
    ptr = NULL;
    ptr = createPath (propertyIconsFP, sizeof(propertyIconsFP), path_cfg, sep, propertyIconsFN);
    if ((fp = fopen(ptr, "rt"))==NULL)
    {
        printf("Can not open file [%s].\n", ptr);
        return 1;
    }
    // Filtering \r & \n
    for (i=1;i<=propertiesN;i++)
    {
        fgets(tmp_char, sizeof(propertyIcons[i-1]), fp);
        j = 0; j_max = strlen(tmp_char) - 1; k = 0;
        while (j <= j_max)
        {
            c = tmp_char[j];
            if ((c != '\r') && (c != '\n'))
            {
                propertyIcons[i-1].text[k] = c;
                k++;
            }
            j++;
        }
        propertyIcons[i-1].text[k] = '\0';
    }
    OK = 1; OK = fclose(fp);
    if (OK != 0)
    {
        printf("Can not close file [%s].\n", ptr);
        return 1;
    }

    //Creating filenames for Properties's Files // char128 propertiesFPs[propertiesN];
    ptr = NULL;
    for (i=1;i<=propertiesN;i++)
    {
        sprintf(tmp_char, "%d", i);
        ptr = NULL;
        ptr = createPath2 (propertiesFPs[i-1].text, sizeof(propertiesFPs[i-1].text), path_cfg, sep, tmp_char, ext);
    }

    // Read to line propertiesData[propertiesN];
    for (i=1;i<=propertiesN;i++)
    {
        ptr = NULL;
        j = 0; //cursor in string
        propertiesData[i-1].text[j] = '\0';
        ptr = propertiesFPs[i-1].text; //name of file
        // Get fileSize
        if ((fp = fopen(ptr, "rb"))==NULL)
        {
            printf("Can not open file [%s].\n", ptr);
            return 1;
        }
        fileSize = 0;
        fseek(fp, 0, SEEK_END);
        fileSize = ftell(fp);
        OK = 1; OK = fclose(fp);
        if (OK != 0)
        {
            printf("Can not close file [%s].\n", ptr);
            return 1;
        }

        if ((fp = fopen(ptr, "r"))==NULL)
        {
            printf("Can not open file [%s].\n", ptr);
            return 1;
        }
        c = '\0'; j_max = 0;
        memset(propertiesData[i-1].text,'\0',sizeof(propertiesData[i-1].text));

        j_max = sizeof(propertiesData[i-1].text);
        if (fileSize > j_max)
        {
            printf("File is too big [%s].\n", ptr);
            return 1;
        }

        c = fgetc(fp);
        while (!feof(fp))
        {
            propertiesData[i-1].text[j] = c;
            j++;
            c = fgetc(fp);
        }
        propertiesData[i-1].text[j] = '\0';

        OK = 1; OK = fclose(fp);
        if (OK != 0)
        {
            printf("Can not close file [%s].\n", ptr);
            return 1;
        }
    }


    //Writing a HTML in TEXT Mode //--------------------------------------------
    ptr = NULL;
    ptr = createPath (outFP_t, sizeof(outFP_t), path_out, sep, itemFN_t);
    if ((fp = fopen(ptr, "w"))==NULL)
    {
        printf("Can not open file [%s].\n", ptr);
        return 1;
    }
    //writing
    fputs(doctype_t, fp);
    fputs(nl, fp);
    fputs(welcome_t, fp);
    fputs(nl, fp);
    fputs(html1, fp);
    fputs(nl, fp);
    fputs(head1, fp);
    fputs(title1, fp);
    fputs(siteTitle, fp);
    fputs(title2, fp);
	fputs(meta_t, fp);
    fputs(head2, fp);
    fputs(nl, fp);
    fputs(body1_t, fp);
    fputs(nl, fp);
    fputs(back_to_db_t, fp);
    fputs(br, fp);
    fputs(nl, fp);
    fputs(headerSeparator_t, fp);
    fputs(nl, fp);
    fputs(header1_t, fp);
    fputs(game_title.text, fp);
    fputs(header2, fp);
    fputs(nl, fp);
    fputs(headerSeparator_t, fp);
    fputs(nl, fp);
    fputs(nl, fp);
    //group
    for (i=1;i<=groupsN;i++)
    {
        fputs(b1, fp);
        fputs(groups[i-1].text, fp);
        fputs(b2, fp);
        fputs(br, fp);
        fputs(nl, fp);
        fputs(br, fp);
        fputs(nl, fp);
        fputs(nl, fp);
        j_max = 0;
        while (groupcat[i-1][j_max] > 0) { j_max++; }
        for (j=1;j<=j_max;j++)
        {
            k = groupcat[i-1][j-1];
            fputs(b1, fp);
            fputs(properties[k-1].text, fp);
            fputs(b2, fp);
            fputs(br, fp);
            fputs(nl, fp);
            fputs(propertiesData[k-1].text, fp);
            fputs(br, fp);
            fputs(br, fp);
            fputs(nl, fp);
            fputs(nl, fp);
        }
    }
    fputs(body2, fp);
    fputs(nl, fp);
    fputs(html2, fp);
    //closing
    OK = 1; OK = fclose(fp);
    if (OK != 0)
    {
        printf("Can not close file [%s].\n", ptr);
        return 1;
    }


    //Writing a HTML in GRAPHIC Mode //-----------------------------------------
    ptr = NULL;
    ptr = createPath (outFP_g, sizeof(outFP_g), path_out, sep, itemFN_g);
    if ((fp = fopen(ptr, "w"))==NULL)
    {
        printf("Can not open file [%s].\n", ptr);
        return 1;
    }
    //writing
    fputs(doctype_g, fp);
    fputs(nl, fp);
    fputs(welcome_g, fp);
    fputs(nl, fp);
    fputs(html1, fp);
    fputs(nl, fp);
    fputs(head1, fp);
    fputs(title1, fp);
    fputs(siteTitle, fp);
    fputs(title2, fp);
	fputs(meta_g, fp);
    fputs(head2, fp);
    fputs(nl, fp);
    fputs(body1_g, fp);
    fputs(nl, fp);
    fputs(back_to_db_g, fp);
    fputs(nl, fp);
    fputs(headerSeparator_g, fp);
    fputs(nl, fp);
    fputs(header1_g, fp);
    fputs(game_title.text, fp);
    fputs(header2, fp);
    fputs(nl, fp);
    fputs(headerSeparator_g, fp);
    fputs(nl, fp);
    //group
    for (i=1;i<=groupsN;i++)
    {
        fputs(groupIcons[i-1].text, fp);
        fputs(space, fp);
        fputs(b1, fp);
        fputs(groups[i-1].text, fp);
        fputs(b2, fp);
        fputs(br, fp);
        fputs(nl, fp);
        fputs(nl, fp);
        fputs(table1, fp);
        fputs(nl, fp);
        blue = true;
        j_max = 0;
        while (groupcat[i-1][j_max] > 0) { j_max++; }
        for (j=1;j<=j_max;j++)
        {
            k = groupcat[i-1][j-1];
            if (blue) { fputs(tr1_blue, fp); } else { fputs(tr1_white, fp); }
            fputs(propertyIcons[k-1].text, fp);
            if (blue) { fputs(tr2_blue, fp); } else { fputs(tr2_white, fp); }
            fputs(b1, fp);
            fputs(properties[k-1].text, fp);
            fputs(b2, fp);
            if (blue) { fputs(tr3_blue, fp); } else { fputs(tr3_white, fp); }
            fputs(nl, fp);
            fputs(propertiesData[k-1].text, fp);
            fputs(nl, fp);
            if (blue) { fputs(tr4_blue, fp); } else { fputs(tr4_white, fp); }
            blue = !blue;
        }
        fputs(trspacer, fp);
        fputs(nl, fp);
        fputs(table2, fp);
        fputs(nl, fp);
        fputs(nl, fp);
    }
    fputs(body2, fp);
    fputs(nl, fp);
    fputs(html2, fp);
    //closing
    OK = 1; OK = fclose(fp);
    if (OK != 0)
    {
        printf("Can not close file [%s].\n", ptr);
        return 1;
    }

    ////////////////////////////////////////////////////////////////////////////

    //printf("Job is done. Have a good day.\r\n");

    return 0;
}
