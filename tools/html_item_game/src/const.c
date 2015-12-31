// Legacy Vault
// html_item_game
// const.c
// Version 1.3

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "const.h"

// Consts
extern const char *tool_name = "html_item_game tool";
extern const char *tool_version = "1.3";
extern const int groupsN = 3; // G1 = {P1..P11}, G2 = {P4,P12..P16}, G3 = {P17..P25}.
extern const int propertiesN = 26; // (!) Syncronize it with groupcat[*][*]
extern const char *doctype_t = "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 3.2 Final//EN\">";
extern const char *doctype_g = "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 3.2 Final//EN\">";
extern const char *welcome_t = "<!-- WELCOME TO THE [LEGACY VAULT]! THIS HTML PAGE IS IN TEXT MODE -->";
extern const char *welcome_g = "<!-- WELCOME TO THE [LEGACY VAULT]! THIS HTML PAGE IS IN GRAPHIC MODE -->";
extern const char *meta_t = "<meta charset=\"utf-8\">\r\n<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\">\r\n<meta name=\"author\" content=\"Legacy Vault\">\r\n<meta name=\"description\" content=\"Legacy Vault Project is a Storage Place for Media Image Hash Sums which are used to check the Integrity of old Games CDs, oldschool Programs DVDs, as well as rare, classic, abandoned or retro MSDOS and Windows Stuff. Audio, Music, ancient and outdated Literature is also a Kind of History Preservation Act as they are Memory kept in compact Discs/Disks and 3.5 Inch Floppy Diskettes. All for Copleteness, Tradition and Order of Information on Planet Earth.\">\r\n<meta name=\"keywords\" content=\"Legacy, Vault, image, hash, integrity, check, storage, media, old, games, programs, oldschool, rare, classic, abandon, retro, dos, msdos, windows, audio, music, literature, ancient, outdated, history, preservation, project, memory, disc, disk, diskette, floppy, 3.5, compact, CD, DVD, copleteness, tradition, information, order, planet, earth\">\r\n";
extern const char *meta_g = "<meta charset=\"utf-8\">\r\n<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\">\r\n<meta name=\"author\" content=\"Legacy Vault\">\r\n<meta name=\"description\" content=\"Legacy Vault Project is a Storage Place for Media Image Hash Sums which are used to check the Integrity of old Games CDs, oldschool Programs DVDs, as well as rare, classic, abandoned or retro MSDOS and Windows Stuff. Audio, Music, ancient and outdated Literature is also a Kind of History Preservation Act as they are Memory kept in compact Discs/Disks and 3.5 Inch Floppy Diskettes. All for Copleteness, Tradition and Order of Information on Planet Earth.\">\r\n<meta name=\"keywords\" content=\"Legacy, Vault, image, hash, integrity, check, storage, media, old, games, programs, oldschool, rare, classic, abandon, retro, dos, msdos, windows, audio, music, literature, ancient, outdated, history, preservation, project, memory, disc, disk, diskette, floppy, 3.5, compact, CD, DVD, copleteness, tradition, information, order, planet, earth\">\r\n";
extern const char *b1 = "<b>";
extern const char *b2 = "</b>";
extern const char *br = "<br>";
extern const char *dv = ":";
extern const char *html1 = "<html>";
extern const char *html2 = "</html>";
extern const char *head1 = "<head>";
extern const char *head2 = "</head>";
extern const char *title1 = "<title>";
extern const char *title2 = "</title>";
extern const char *body1_t = "<body bgcolor=\"#000000\" text=\"#00FF00\" link=\"#00FF00\" vlink=\"#00FF00\" alink=\"#00FF00\">";
extern const char *body1_g = "<body bgcolor=\"#FFFFFF\" text=\"#000000\" link=\"#0000EE\" vlink=\"#551A8B\" alink=\"#804080\">";
extern const char *body2 = "</body>";
extern const char *back_to_db_t = "<a href=\"../db_t.htm\" title=\"Click here to return to previous Page\">[Go Back]</a>";
extern const char *back_to_db_g = "<a href=\"../db_g.htm\" title=\"Click here to return to previous Page\"><img src=\"../../img/ico/globe.png\" width=\"32\" height=\"32\" align=\"right\" alt=\"[Go Back]\"></a>";
extern const char *header1_t = "<h3>";
extern const char *header1_g = "<h3 align=\"center\">";
extern const char *headerSeparator_t = "-------------------------------------<br>";
extern const char *headerSeparator_g = "";
extern const char *header2 = "</h3>";
extern const char *space = " ";
extern const char *table1 = "<table cellpadding=\"0\" cellspacing=\"0\" border=\"0\" align=\"left\" width=\"100%\">";
extern const char *table2 = "</table>";
extern const char *tr1_blue = "<tr height=\"4\">\r\n\t<td colspan=\"5\" bgcolor=\"lightblue\"> </td>\r\n</tr>\r\n<tr bgcolor=\"lightblue\" height=\"36\">\r\n\t<td width=\"20\"></td>\r\n\t<td valign=\"top\" width=\"40\">";
extern const char *tr2_blue = "</td>\r\n\t<td valign=\"top\" align=\"right\" width=\"20\">";
extern const char *tr3_blue = "</td>\r\n\t<td width=\"8\"></td>\r\n\t<td valign=\"middle\" align=\"left\">";
extern const char *tr4_blue = "</td>\r\n</tr>\r\n<tr height=\"4\"><td colspan=\"5\" bgcolor=\"lightblue\"> </td></tr>";
extern const char *tr1_white = "<tr height=\"4\">\r\n\t<td colspan=\"5\" bgcolor=\"\"> </td>\r\n</tr>\r\n<tr bgcolor=\"\" height=\"36\">\r\n\t<td width=\"20\"></td>\r\n\t<td valign=\"top\" width=\"40\">";
extern const char *tr2_white = "</td>\r\n\t<td valign=\"top\" align=\"right\" width=\"20\">";
extern const char *tr3_white = "</td>\r\n\t<td width=\"8\"></td>\r\n\t<td valign=\"middle\" align=\"left\">";
extern const char *tr4_white = "</td>\r\n</tr>\r\n<tr height=\"4\"><td colspan=\"5\" bgcolor=\"\"> </td></tr>";
extern const char *trspacer = "<tr height=\"32\"><td colspan=\"3\"> </td></tr>";

extern int groupcat[3][26] = { {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}, {4, 12, 13, 14, 15, 16}, {17, 18, 19, 20, 21, 22, 23, 24, 25, 26} };

// OS Specific
extern const char *sep = "/"; // Path separator is "\\" in Windows, "/" in Linux OS!
extern const char *nl = "\r\n";

// Configuration
extern const char *siteTitle = "[LEGACY VAULT]";
extern const char *titleFN = "title.txt";
extern const char *groupsFN = "groups.txt";
extern const char *groupIconsFN = "group_icons.txt";
extern const char *propertiesFN = "properties.txt";
extern const char *propertyIconsFN = "property_icons.txt";
extern const char *itemFN_t = "item_t.htm";
extern const char *itemFN_g = "item_g.htm";
extern const char *ext = ".txt";
