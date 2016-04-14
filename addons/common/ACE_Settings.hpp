class ACE_Settings {
    /*
     * class GVAR(sampleSetting) {
     *     value = 1; // Value
     *     typeName = "SCALAR"; // Type (SCALAR, BOOL, STRING, ARRAY, COLOR)
     *     force = 0; // Force the setting?
     *     isClientSettable = 1; // Does it appear on the options menu?
     *
     *     // The following settings only apply when isClientSettable == 1
     *     displayName = "$STR_ACE_Common_SettingName"; // Stringtable entry with the setting name
     *     description = "$STR_ACE_Common_SettingDescription"; // Stringtable entry with the setting description
     *
     *     // Only applies if typeName == "SCALAR";
     *     values[] = {"Disabled", "Enabled", "Only Cursor", "Only On Keypress", "Only Cursor and KeyPress"}; // Stringtable entries that describe the options
     * };
     */
    class GVAR(forceAllSettings) {
        value = 0;
        typeName = "BOOL";
    };
    class GVAR(checkPBOsAction) {
        value = 0;
        typeName = "SCALAR";
        isClientSettable = 0;
        values[] = {CSTRING(CheckPBO_Action_WarnOnce), CSTRING(CheckPBO_Action_WarnPerm), CSTRING(CheckPBO_Action_Kick)};
    };
    class GVAR(checkPBOsCheckAll) {
        value = 0;
        typeName = "BOOL";
        isClientSettable = 0;
    };
    class GVAR(checkPBOsWhitelist) {
        value = "['DragonFyre_Bullethits','DragonFyre_Environment','DragonFyre_Explosions','DragonFyre_GlobalFilters','DragonFyre_Sonic_Cracks','DragonFyre_230mm_Titan','DragonFyre_Air_Weapons','DragonFyre_35mm_Autocannon','DragonFyre_120mm_Cannon','DragonFyre_Gatling','DragonFyre_Gatling_30mm_Plane_CAS_01','DragonFyre_Cannon_30mm_Plane_CAS_02','DragonFyre_CTWS_Autocannon','DragonFyre_DAGR','DragonFyre_DAR','DragonFyre_30mm_Cannon','DragonFyre_Gatling_Weapons','DragonFyre_155mm_AMOS','DragonFyre_LMG_Coax','DragonFyre_LMGRCWS','DragonFyre_GMG20','DragonFyre_GMG40','DragonFyre_127','DragonFyre_Skalpel_ATGM','DragonFyre_Skyfire','DragonFyre_Veh_Titan','DragonFyre_4Five45','DragonFyre_ACPC','DragonFyre_ASP1','DFyre_MX','DragonFyre_Cyrus','DragonFyre_M6','DragonFyre_Khaybar','DragonFyre_M320R','DragonFyre_MAR10','DragonFyre_Mk1EMR','DragonFyre_Mk14','DragonFyre_EBR','DragonFyre_FS2000','DragonFyre_M200','DragonFyre_Navid','DragonFyre_NLAW','DragonFyre_PCML','DragonFyre_PDW','DragonFyre_Rahim','DragonFyre_Rook40','DragonFyre_RPG32','DragonFyre_SPMG','DragonFyre_Scorpian','DragonFyre_Titan','DragonFyre_TRG20','DragonFyre_UGL','DragonFyre_SDAR','DragonFyre_Vector','DragonFyre_Zafir','DragonFyre_Zubr45','DragonFyre_Movement','DragonFyre_FighterPlane3','DragonFyre_CAS_Plane1','DragonFyre_AH99_Blackfoot','DragonFyre_AH9_Pawnee','DragonFyre_UAV_1','DragonFyre_CH67_Huron','DragonFyre_CH49_Mohawk','DragonFyre_Mi290_Taru','DragonFyre_Mi48_Kajman','DragonFyre_UAV_2','DragonFyre_Po30_Orca','DragonFyre_CAS_Plane2','DragonFyre_UH80_GhostHawk','DragonFyre_WY55_Hellcat','DragonFyre_Boat_Armed_1','DragonFyre_2S9_Sorcher','DragonFyre_BTRK_Kamysh','DragonFyre_FV720_Mora','DragonFyre_IFV6a_Cheetah','DragonFyre_IFV6c_Panther','DragonFyre_M2A1_Slammer','DragonFyre_M4_Scorcher','DragonFyre_M5_Sandstorm','DragonFyre_MBT52_Kuma','DragonFyre_T100_Varsuk','DragonFyre_ZSU39_Tigris','DragonFyre_AFV4_Gorgon','DragonFyre_AMV7_Marshal','DragonFyre_Hatchback','DragonFyre_truck1','DragonFyre_Hunter','DragonFyre_Ifrit','DragonFyre_MSE3_Marid','DragonFyre_Offroad','DragonFyre_Quadbike','DragonFyre_Strider','DragonFyre_SUV','DragonFyre_Truck2','DragonFyre_Van','DragonFyre_Truck3','life_server']";
        typeName = "STRING";
        isClientSettable = 0;
    };
    /*class GVAR(enableNumberHotkeys) {
        value = 1;
        typeName = "BOOL";
        isClientSettable = 1;
        displayName = CSTRING(EnableNumberHotkeys);
    };*/
    class GVAR(settingFeedbackIcons) {
        value = 1;
        typeName = "SCALAR";
        force = 0;
        isClientSettable = 1;
        displayName = CSTRING(SettingFeedbackIconsName);
        description = CSTRING(SettingFeedbackIconsDesc);
        values[] = {ECSTRING(optionsmenu,Hide), ECSTRING(optionsmenu,TopRightDown), ECSTRING(optionsmenu,TopRightLeft), ECSTRING(optionsmenu,TopLeftDown), ECSTRING(optionsmenu,TopLeftRight)};
    };
    class GVAR(SettingProgressBarLocation) {
        value = 0;
        typeName = "SCALAR";
        force = 0;
        isClientSettable = 1;
        displayName = CSTRING(SettingProgressbarLocationName);
        description = CSTRING(SettingProgressbarLocationDesc);
        values[] = {ECSTRING(optionsmenu,Top), ECSTRING(optionsmenu,Bottom)};
    };
    class GVAR(displayTextColor) {
        value[] = {0,0,0,0.1};
        typeName = "COLOR";
        isClientSettable = 1;
        displayName = CSTRING(SettingDisplayTextColorName);
        description = CSTRING(SettingDisplayTextColorDesc);
    };
    class GVAR(displayTextFontColor) {
        value[] = {1,1,1,1};
        typeName = "COLOR";
        isClientSettable = 1;
        displayName = CSTRING(SettingDisplayTextFontColorName);
        description = CSTRING(SettingDisplayTextFontColorDesc);
    };
};
