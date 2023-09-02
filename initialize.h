#ifndef INITIALIZE_H
#define INITIALIZE_H

#include "ownable.h"


// academic building initializing elements.
/*string name, string type, player* owner, int purchase_cost, string monopoly_block, 
int improvement_cost, int improvement_level, int* level_fee)*/

academic_building AL{"AL", "academic", nullptr, 40, "Arts1", 50, 0, {2, 10, 30, 90, 160, 250}};
academic_building ML{"ML", "academic", nullptr, 60, "Arts1", 50, 0, {4, 20, 60, 180, 320, 450}};
academic_building ECH{"ECH", "academic", nullptr, 100, "Arts2", 50, 0, {6, 30, 90, 270, 400, 550}};
academic_building PAS{"PAS", "academic", nullptr, 100, "Arts2", 50, 0, {6, 30, 90, 270, 400, 550}};
academic_building HH{"HH", "academic", nullptr, 120, "Arts2", 50, 0, {8, 40, 100, 300, 450, 600}};
academic_building RCH{"RCH", "academic", nullptr, 140, "Eng", 100, 0, {10, 50, 150, 450, 625, 750}};
academic_building DWE{"DWE", "academic", nullptr, 140, "Eng", 100, 0, {10, 50, 150, 450, 625, 750}};
academic_building CPH{"CPH", "academic", nullptr, 160, "Eng", 100, 0, {12, 60, 180, 500, 700, 900}};
academic_building LHI{"LHI", "academic", nullptr, 180, "Health", 100, 0, {14, 70, 200, 550, 750, 950}};
academic_building BMH{"BMH", "academic", nullptr, 180, "Health", 100, 0, {14, 70, 200, 550, 750, 950}};
academic_building OPT{"OPT", "academic", nullptr, 200, "Health", 100, 0, {16, 80, 220, 600, 800, 1000}};
academic_building EV1{"EV1", "academic", nullptr, 220, "Env", 150, 0, {18, 90, 250, 700, 875, 1050}};
academic_building EV2{"EV2", "academic", nullptr, 220, "Env", 150, 0, {18, 90, 250, 700, 875, 1050}};
academic_building EV3{"EV3", "academic", nullptr, 240, "Env", 150, 0, {20, 100, 300, 750, 925, 1100}};
academic_building PHYS{"PHYS", "academic", nullptr, 260, "Sci1", 150, 0, {22, 110, 330, 800, 975, 1150}};
academic_building B1{"B1", "academic", nullptr, 260, "Sci1", 150, 0, {22, 110, 330, 800, 975, 1150}};
academic_building B2{"B2", "academic", nullptr, 280, "Sci1", 150, 0, {24, 120, 360, 850, 1025, 1200}};
academic_building EIT{"EIT", "academic", nullptr, 300, "Sci2", 200, 0, {26, 130, 390, 900, 1100, 1275}};
academic_building ESC{"ESC", "academic", nullptr, 300, "Sci2", 200, 0, {26, 130, 390, 900, 1100, 1275}};
academic_building C2{"C2", "academic", nullptr, 320, "Sci2", 200, 0, {28, 150, 450, 1000, 1200, 1400}};
academic_building MC{"MC", "academic", nullptr, 350, "Math", 200, 0, {35, 175, 500, 1100, 1300, 1500}};
academic_building DC{"DC", "academic", nullptr, 400, "Math", 200, 0, {50, 200, 600, 1400, 1700, 2000}};


// residence(string name, string type, player* owner, int purchase_cost)

residence MKV{"MKV", "residence", nullptr, 200};
residence UMP{"UMP", "residence", nullptr, 200};
residence V1{"V1", "residence", nullptr, 200};
residence REV{"REV", "residence", nullptr, 200};

//     gym(string name, string type, player* owner, int purchase_cost)

gym PAC{"PAC", "gym", nullptr, 150};
gym CIF{"CIF", "gym", nullptr, 150};





#endif
