#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void banner() {
    printf("          .....:                                                                                  :.....          \n");
    printf("          ...........                           ..................                           ...........          \n");
    printf("             #  .........                 ..............................                 .........  #             \n");
    printf("            ######   .......           .........  ####       ###  :........           .......   ######            \n");
    printf("            #####       ......      .......      #####      ######     .......      ......       #####            \n");
    printf("            #####     ####......  ......###      #####      #####      ###......  ......####     #####            \n");
    printf("           #####     ###### .........  #####     #####      #####     #####  ......... ######     #####           \n");
    printf("           #####     #####    .....     #####     ####      ####     #####     .....    ######    #####           \n");
    printf("           ####     #####     #...#      ####     ####      ####     ####      #...#     #####     ####           \n");
    printf("          #####    #####     ### ####     ####     ####    ####     ####     #### ###     #####    #####          \n");
    printf("          ####    ####     ###########     ####    ###      ###    ####     ###########     ####    ####          \n");
    printf("          ++++ ######     #############     ### ++++++++++++++++++ ###     #############     ###### ++++          \n");
    printf("          +++++++++##   ################    ++++++++++++++++++++++++++    ################   ##+++++++++          \n");
    printf("          ++++++++++++###################++++++++++++++++++++++++++++++++###################++++++++++++          \n");
    printf("                      ++############### +++++++++++            *++++++++++ ###############++                      \n");
    printf("                         #############++++++++                      ++++++++#############                         \n");
    printf("                          ###########+++++++                          +++++++###########                          \n");
    printf("                           ######### +++++                              +++++ #########                           \n");
    printf("                           #########+++++                                +++++#########                           \n");
    printf("                           #########++++                                  ++++#########                           \n");
    printf("                          ########## +++                                   +++##########                          \n");
    printf("                          ###########++           %%%%++++++%%%%               ++###########                          \n");
    printf("                         ############ ++    %%%%%%%%%%++....+#%%%%%%%%             ++############                         \n");
    printf("                       ############### +    %%%%%%%%%%+++ .. +%%%%%%%%%%           +###############                       \n");
    printf("                      ##################+  %%%%%%%%+ :......... ++%%%%%%       +##################                      \n");
    printf("                      ################# ++ %%%%%%++............ +%%%%%%      ++#################                      \n"); 
    printf("                         ############ ++++ %%%%%%*+ .............++%%%%%%    ++++############                         \n");
    printf("                           ..........+++ %%%%%%%%+ .............. +%%%%%%%%     +++..........                           \n");
    printf("                           ...........    %%%%%%++... ............+%%%%%%       ...........                           \n");
    printf("                            .......       %%%%%%++:..............++%%%%%%          .......                              \n");
    printf("                            .......        %%%%%%+ .......... ..++%%%%            .......                              \n");
    printf("                            .......         %%%%%%++.......... ..++%%            .......                              \n");
    printf("                            .......          %%%%+ .......... . +%%             .......                              \n");
    printf("                            .......            %% ........... +%%              .......                              \n");
    printf("                            .......              ............ +              .......                              \n");
    printf("                            .......                 .........                :......                              \n");
    printf("                            ......:                 :..:...:                 :......                              \n");
    printf("                            :.......                  ..:...                 ......:                            \n");
    printf("                            .......                   ......                 .......                            \n");
    printf("                            .......     %%%%%%%%%%%%..... ...%%%%%%%%%%%%%%     .......                            \n");
    printf("                            .......%%%%%%%%%%..............%%%%%%%%%%%%%%%%%%%%.......                            \n");
    printf("                            .......%%%%:.................  .%%%%%%%%%%%%%%%%%%%%.......                            \n");
    printf("                            ...............................%%%%%%%%%%%%%%%%%%%%.......                            \n");
    printf("                            .............................%%%%%%%%%%%%%%%%%%%%%%.......                            \n");
    printf("                            ...........................%%%%%%%%%%%%%%%%%%%%%%%%.......                   \n\n");
}

void flag() {
    printf("hfct{Gr4c14s_p0r_p4rt1c1p4r}\n");
    exit(0);
}



int main() {
    banner();

    char comment[50];
    printf("Deja una reseña sobre nuestro CTF: ");
    gets(comment);
    printf("Gracias! Esperamos que lo hayas disfrutado.\n");
    printf("\n(Te crees que te voy a dar una flag solo por quejarte?)\n\n");

    return 0;
}
