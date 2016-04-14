
class CBA_Extended_EventHandlers;

class CfgVehicles {
    class ACE_Module;
    class ACE_ModuleInteraction: ACE_Module {
        author = ECSTRING(common,ACETeam);
        category = "ACE";
        displayName = CSTRING(Module_DisplayName);
        function = "ACE_Interaction_fnc_moduleInteraction";
        scope = 2;
        isGlobal = 1;
        isSingular = 1;
        icon = PATHTOF(UI\Icon_Module_Interaction_ca.paa);
        class Arguments {
            class EnableTeamManagement {
                displayName = CSTRING(EnableTeamManagement_DisplayName);
                description = CSTRING(EnableTeamManagement_Description);
                typeName = "BOOL";
                defaultValue = 1;
            };
        };
        class ModuleDescription {
            description = CSTRING(Module_Description);
        };
    };

    class Man;
    class CAManBase: Man {
        class ACE_Actions {
            class ACE_MainActions {
                displayName = CSTRING(MainAction);
                distance = 4;
                condition = QUOTE(true);
                statement = "";
                icon = "\a3\ui_f\data\IGUI\Cfg\Actions\eject_ca.paa";
                selection = "pelvis";
				
				class ACE_Carte {
					displayName = "Plaque gendarme";
					distance = 4;
					condition = "_target isKindOf 'Man' && {alive _target} && {playerSide == west}";
					statement = "[_target,'cop'] spawn life_fnc_showIdentity";
					exceptions[] = {"isNotSwimming"};
					showDisabled = 0;
					priority = 2.6;
				};
				class ACE_Carte2 {
					displayName = "Presenter carte";
					distance = 4;
					condition = "_target isKindOf 'Man' && {alive _target} && {playerSide == civilian}";
					statement = "[_target,'civ'] spawn life_fnc_showIdentity";
					exceptions[] = {"isNotSwimming"};
					showDisabled = 0;
					priority = 2.7;
				};
				class ACE_Carte3 {
					displayName = "Plaque pompier";
					distance = 4;
					condition = "_target isKindOf 'Man' && {alive _target} && {playerSide == resistance}";
					statement = "[_target,'med'] spawn life_fnc_showIdentity";
					exceptions[] = {"isNotSwimming"};
					showDisabled = 0;
					priority = 2.7;
				};
				class ACE_Carte4 {
					displayName = "Plaque armé";
					distance = 4;
					condition = "_target isKindOf 'Man' && {alive _target} && {playerSide == east}";
					statement = "[_target,'army'] spawn life_fnc_showIdentity";
					exceptions[] = {"isNotSwimming"};
					showDisabled = 0;
					priority = 2.7;
				};
				
				class ACE_Copinteraction {
					displayName = "Gendarme";
					distance = 4;
					condition = "(alive _target) && {isPlayer _target} && {_target isKindOf 'Man'} && {(_target getVariable['ACE_Captives_isHandcuffed',false]) OR (_target getVariable['ACE_Captives_isSurrendering',false])} && {playerSide == west} && {side _target in [civilian,independent]}";
					statement = "";
					showDisabled = 0;
					priority = 3.2;
					subMenu[] = {"ACE_Copinteraction",0};
					hotkey = "C";
					class ACE_CopCheckLicenses {
						displayName = "$STR_pInAct_checkLicenses";
						distance = 4;
						condition = "alive _target && {isPlayer _target} && {_target isKindOf 'Man'} && {(_target getVariable['ACE_Captives_isHandcuffed',false]) OR (_target getVariable['ACE_Captives_isSurrendering',false])} && {playerSide == west} && {side _target in [civilian,independent]}";
						statement = "[player] remoteExecCall ['life_fnc_licenseCheck',_target]";
						showDisabled = 1;
						priority = 2.4;
						hotkey = "L";
					};
					class ACE_CopSearch {
						displayName = "$STR_pInAct_SearchPlayer";
						distance = 4;
						condition = "alive _target && {isPlayer _target} && {_target isKindOf 'Man'} && {(_target getVariable['ACE_Captives_isHandcuffed',false]) OR (_target getVariable['ACE_Captives_isSurrendering',false])} && {playerSide == west} && {side _target in [civilian,independent]}";
						statement = "[_target] spawn life_fnc_searchAction;";
						showDisabled = 1;
						priority = 2.4;
						hotkey = "S";
					};
					class ACE_AlcoholTest {
						displayName = "Test Alcoolémie";
						distance = 4;
						condition = "alive _target && {isPlayer _target} && {_target isKindOf 'Man'} && {(_target getVariable['ACE_Captives_isHandcuffed',false])} && {playerSide == west} && {side _target in [civilian,independent]}";
						statement = "[_target] spawn life_fnc_alcoholTest;";
						showDisabled = 1;
						priority = 2.4;
						hotkey = "A";
					};
					class ACE_CopTicket {
						displayName = "$STR_pInAct_TicketBtn";
						distance = 4;
						condition = "alive _target && {isPlayer _target} && {_target isKindOf 'Man'} && {(_target getVariable['ACE_Captives_isHandcuffed',false])} && {playerSide == west} && {side _target in [civilian,independent]}";
						statement = "[_target] call life_fnc_ticketAction";
						showDisabled = 1;
						priority = 2.2;
						hotkey = "T";
					};
					class ACE_Prison {
						displayName = "$STR_pInAct_Arrest";
						distance = 4;
						condition = "alive _target && {isPlayer _target} && {_target isKindOf 'Man'} && {(_target getVariable['ACE_Captives_isHandcuffed',false])} && {playerSide == west} && {side _target in [civilian,independent]} && (player distance (getMarkerPos 'jail_send') < 30)";
						statement = "[_target] call life_fnc_showArrestDialog;";
						showDisabled = 1;
						priority = 2.5;
						hotkey = "P";
					};
				};
            };

            class ACE_Torso {
                displayName = CSTRING(Torso);
                selection = "spine3";
                distance = 1.50;
                condition = "";
                statement = "";
            };
            class ACE_Head {
                displayName = CSTRING(Head);
                selection = "pilot";
                distance = 1.50;
                condition = "";
                statement = "";
            };
            class ACE_ArmLeft {
                displayName = CSTRING(ArmLeft);
                selection = "LeftForeArm";
                distance = 1.50;
                condition = "";
                statement = "";
            };
            class ACE_ArmRight {
                displayName = CSTRING(ArmRight);
                selection = "RightForeArm";
                distance = 1.50;
                condition = "";
                statement = "";
            };
            class ACE_LegLeft {
                displayName = CSTRING(LegLeft);
                selection = "LKnee";
                distance = 1.50;
                condition = "";
                statement = "";
            };
            class ACE_LegRight {
                displayName = CSTRING(LegRight);
                selection = "RKnee";
                distance = 1.50;
                condition = "";
                statement = "";
            };
            class ACE_Weapon {
                displayName = CSTRING(Weapon);
                position = QUOTE(call DFUNC(getWeaponPos));
                distance = 1.50;
                condition = "";
                statement = "";
            };
        };

        class ACE_SelfActions {

            class ACE_Equipment {
                displayName = CSTRING(Equipment);
                condition = QUOTE(true);
                exceptions[] = {"isNotInside", "notOnMap", "isNotSitting"};
                statement = "";
                showDisabled = 1;
                priority = 4.5;
                icon = "";  // @todo
            };
        };
    };

    class LandVehicle;
    class Car: LandVehicle {
        class ACE_Actions {
            class ACE_MainActions {
                displayName = CSTRING(MainAction);
                selection = "";
                distance = 10;
                condition = "true";
                class ACE_Passengers {
                    displayName = CSTRING(Passengers);
                    condition = "true";
                    statement = "";
                    insertChildren = QUOTE(_this call DFUNC(addPassengersActions));
                };
				
				class ACE_repair {
					displayName = "$STR_vInAct_Repair";
					distance = 4;
					condition = "alive _target && {speed _target == 0} && {(damage _target < 1)}";
					statement = "[_target] spawn life_fnc_repairTruck";
					showDisabled = 0;
					priority = 1.6;
				};
                /*class ACE_TempestMine {
					displayName = "$STR_vInAct_DeviceMine";
					distance = 4;
					condition = "alive _target && {speed _target == 0} && (isNil {(_target getVariable 'mining')} || !local _target) && (_target in life_vehicles) && typeOf _target == 'O_Truck_03_device_F'";
					statement = "[_target] spawn life_fnc_deviceMine";
					showDisabled = 0;
					priority = 1.6;
				};
                 class ACE_PumpOil {
					displayName = "Lancer la pompe";
					distance = 4;
					condition = "alive _target && {speed _target == 0} && (isNil {(_target getVariable 'pumping')} || !local _target) && (_target in life_vehicles) && typeOf _target == 'O_Truck_03_device_F'";
					statement = "[_target] spawn life_fnc_oilPump";
					showDisabled = 0;
					priority = 1.6;
				};*/
				class ACE_copRegistration {
					displayName = "$STR_vInAct_Registration";
					distance = 4;
					condition = "alive _target && {speed _target == 0} && playerSide == west";
					statement = "[_target] spawn life_fnc_searchVehAction";
					showDisabled = 0;
					priority = 1.6;
				};
                class ACE_copSerchVeh {
					displayName = "$STR_vInAct_SearchVehicle";
					distance = 4;
					condition = "alive _target && {speed _target == 0} && playerSide == west";
					statement = "[_target] spawn life_fnc_vehInvSearch;";
					showDisabled = 0;
					priority = 1.6;
				};
				class ACE_copPullout {
					displayName = "Ejecter";
					distance = 4;
					condition = "alive _target && {speed _target == 0} && {count crew _target != 0} && playerSide in [west,east]";
					statement = "[_target] spawn life_fnc_pulloutAction";
					showDisabled = 0;
					priority = 1.6;
				};
				class ACE_Impound {
					displayName = "$STR_vInAct_Impound";
					distance = 4;
					condition = "alive _target && {speed _target == 0} && playerSide == west";
					statement = "[_target] spawn life_fnc_impoundAction";
					showDisabled = 0;
					priority = 1.6;
				};
				class ACE_Kart {
					displayName = "$STR_vInAct_GetInKart";
					distance = 4;
					condition = "alive _target && {speed _target == 0} && {typeOf (_target) in [""C_Kart_01_Blu_F"",""C_Kart_01_Red_F"",""C_Kart_01_Fuel_F"",""C_Kart_01_Vrana_F""]} && {canMove _target} && {count crew _target != 0} && {locked _target == 0}";
					statement = "player moveInDriver _target";
					showDisabled = 0;
					priority = 1.6;
				};
				class ACE_Unflip {
					displayName = "$STR_vInAct_Unflip";
					distance = 4;
					condition = "alive _target && {speed _target == 0} && {!(typeOf (_target) in [""C_Kart_01_Blu_F"",""C_Kart_01_Red_F"",""C_Kart_01_Fuel_F"",""C_Kart_01_Vrana_F""])} && {!(canMove _target)} && {count crew _target == 0}";
					statement = "_target setPos [getPos _target select 0, getPos _target select 1, (getPos _target select 2)+0.5]";
					showDisabled = 0;
					priority = 1.6;
				};
            };
        };

        class ACE_SelfActions {
            class ACE_Passengers {
                displayName = CSTRING(Passengers);
                condition = "true";
                statement = "";
                insertChildren = QUOTE(_this call DFUNC(addPassengersActions));
            };
        };
    };

    class Tank: LandVehicle {
        class ACE_Actions {
            class ACE_MainActions {
                displayName = CSTRING(MainAction);
                selection = "";
                distance = 10;
                condition = "true";
                class ACE_Passengers {
                    displayName = CSTRING(Passengers);
                    condition = "true";
                    statement = "";
                    insertChildren = QUOTE(_this call DFUNC(addPassengersActions));
                };
				
				class ACE_repair {
					displayName = "$STR_vInAct_Repair";
					distance = 4;
					condition = "alive _target && {speed _target == 0} && {(damage _target < 1)}";
					statement = "[_target] spawn life_fnc_repairTruck";
					showDisabled = 1;
					priority = 1.6;
				};
				class ACE_copRegistration {
					displayName = "$STR_vInAct_Registration";
					distance = 4;
					condition = "alive _target && {speed _target == 0} && {(playerSide in [west,Independent]) OR (player getVariable['is_admin',false])}";
					statement = "[_target] spawn life_fnc_searchVehAction";
					showDisabled = 0;
					priority = 1.6;
				};
                class ACE_copSerchVeh {
					displayName = "$STR_vInAct_SearchVehicle";
					distance = 4;
					condition = "alive _target && {speed _target == 0} && playerSide == west";
					statement = "[_target] spawn life_fnc_vehInvSearch;";
					showDisabled = 0;
					priority = 1.6;
				};
				class ACE_copPullout {
					displayName = "Ejecter";
					distance = 4;
					condition = "alive _target && {speed _target == 0} && {count crew _target != 0} && {playerSide in [west,east]}";
					statement = "[_target] spawn life_fnc_pulloutAction";
					showDisabled = 0;
					priority = 1.6;
				};
				class ACE_Impound {
					displayName = "$STR_vInAct_Impound";
					distance = 4;
					condition = "alive _target && {speed _target == 0} && {(playerSide == west)}";
					statement = "[_target] spawn life_fnc_impoundAction";
					showDisabled = 0;
					priority = 1.6;
				};
				class ACE_Unflip {
					displayName = "$STR_vInAct_Unflip";
					distance = 4;
					condition = "alive _target && {speed _target == 0} && {!(typeOf (_target) in [""C_Kart_01_Blu_F"",""C_Kart_01_Red_F"",""C_Kart_01_Fuel_F"",""C_Kart_01_Vrana_F""])} && {!(canMove _target)} && {count crew _target == 0}";
					statement = "_target setPos [getPos _target select 0, getPos _target select 1, (getPos _target select 2)+0.5]";
					showDisabled = 0;
					priority = 1.6;
				};
            };
        };

        class ACE_SelfActions {
            class ACE_Passengers {
                displayName = CSTRING(Passengers);
                condition = "true";
                statement = "";
                insertChildren = QUOTE(_this call DFUNC(addPassengersActions));
            };
        };
    };

    class Air;
    class Helicopter: Air {
        class ACE_Actions {
            class ACE_MainActions {
                displayName = CSTRING(MainAction);
                selection = "";
                distance = 10;
                condition = "true";
                class ACE_Passengers {
                    displayName = CSTRING(Passengers);
                    condition = "true";
                    statement = "";
                    insertChildren = QUOTE(_this call DFUNC(addPassengersActions));
                };
				
				class ACE_repair {
					displayName = "$STR_vInAct_Repair";
					distance = 4;
					condition = "alive _target && {speed _target == 0} && {(damage _target < 1)}";
					statement = "[_target] spawn life_fnc_repairTruck";
					showDisabled = 1;
					priority = 1.6;
				};
				class ACE_copRegistration {
					displayName = "$STR_vInAct_Registration";
					distance = 4;
					condition = "alive _target && {speed _target == 0} && {(playerSide == west)}";
					statement = "[_target] spawn life_fnc_searchVehAction";
					showDisabled = 0;
					priority = 1.6;
				};
                class ACE_copSerchVeh {
					displayName = "$STR_vInAct_SearchVehicle";
					distance = 4;
					condition = "alive _target && {speed _target == 0} && playerSide == west";
					statement = "[_target] spawn life_fnc_vehInvSearch;";
					showDisabled = 0;
					priority = 1.6;
				};
				class ACE_copPullout {
					displayName = "Ejecter";
					distance = 4;
					condition = "alive _target && {speed _target == 0} && {count crew _target != 0} && {playerSide in [west,east]}";
					statement = "[_target] spawn life_fnc_pulloutAction";
					showDisabled = 0;
					priority = 1.6;
				};
				class ACE_Impound {
					displayName = "$STR_vInAct_Impound";
					distance = 4;
					condition = "alive _target && {speed _target == 0}  && playerSide == west";
					statement = "[_target] spawn life_fnc_impoundAction";
					showDisabled = 0;
					priority = 1.6;
				};
				class ACE_Unflip {
					displayName = "$STR_vInAct_Unflip";
					distance = 4;
					condition = "alive _target && {speed _target == 0} && {!(typeOf (_target) in [""C_Kart_01_Blu_F"",""C_Kart_01_Red_F"",""C_Kart_01_Fuel_F"",""C_Kart_01_Vrana_F""])} && {!(canMove _target)} && {count crew _target == 0}";
					statement = "_target setPos [getPos _target select 0, getPos _target select 1, (getPos _target select 2)+0.5]";
					showDisabled = 0;
					priority = 1.6;
				};
            };
        };

        class ACE_SelfActions {
            class ACE_Passengers {
                displayName = CSTRING(Passengers);
                condition = "true";
                statement = "";
                insertChildren = QUOTE(_this call DFUNC(addPassengersActions));
            };
        };
    };

    class Plane: Air {
        class ACE_Actions {
            class ACE_MainActions {
                displayName = CSTRING(MainAction);
                selection = "";
                distance = 10;
                condition = "true";
                class ACE_Passengers {
                    displayName = CSTRING(Passengers);
                    condition = "true";
                    statement = "";
                    insertChildren = QUOTE(_this call DFUNC(addPassengersActions));
                };
				
				class ACE_repair {
					displayName = "$STR_vInAct_Repair";
					distance = 4;
					condition = "alive _target && {speed _target == 0} && {(damage _target < 1)}";
					statement = "[_target] spawn life_fnc_repairTruck";
					showDisabled = 1;
					priority = 1.6;
				};
				class ACE_copRegistration {
					displayName = "$STR_vInAct_Registration";
					distance = 4;
					condition = "alive _target && {speed _target == 0} && {(playerSide == west)}";
					statement = "[_target] spawn life_fnc_searchVehAction";
					showDisabled = 0;
					priority = 1.6;
				};
                class ACE_copSerchVeh {
					displayName = "$STR_vInAct_SearchVehicle";
					distance = 4;
					condition = "alive _target && {speed _target == 0} && playerSide == west";
					statement = "[_target] spawn life_fnc_vehInvSearch;";
					showDisabled = 0;
					priority = 1.6;
				};
				class ACE_copPullout {
					displayName = "Ejecter";
					distance = 4;
					condition = "alive _target && {speed _target == 0} && {count crew _target != 0} && {playerSide in [west,east]}";
					statement = "[_target] spawn life_fnc_pulloutAction";
					showDisabled = 0;
					priority = 1.6;
				};
				class ACE_Impound {
					displayName = "$STR_vInAct_Impound";
					distance = 4;
					condition = "alive _target && {speed _target == 0} && {(playerSide == west)}";
					statement = "[_target] spawn life_fnc_impoundAction";
					showDisabled = 0;
					priority = 1.6;
				};
				class ACE_Unflip {
					displayName = "$STR_vInAct_Unflip";
					distance = 4;
					condition = "alive _target && {speed _target == 0} && {!(typeOf (_target) in [""C_Kart_01_Blu_F"",""C_Kart_01_Red_F"",""C_Kart_01_Fuel_F"",""C_Kart_01_Vrana_F""])} && {!(canMove _target)} && {count crew _target == 0}";
					statement = "_target setPos [getPos _target select 0, getPos _target select 1, (getPos _target select 2)+0.5]";
					showDisabled = 0;
					priority = 1.6;
				};
            };
        };

        class ACE_SelfActions {
            class ACE_Passengers {
                displayName = CSTRING(Passengers);
                condition = "true";
                statement = "";
                insertChildren = QUOTE(_this call DFUNC(addPassengersActions));
            };
        };
    };

    class Ship;
    class Ship_F: Ship {
        class ACE_Actions {
            class ACE_MainActions {
                displayName = CSTRING(MainAction);
                selection = "";
                distance = 10;
                condition = "true";

                class ACE_Push {
                    displayName = CSTRING(Push);
                    distance = 6;
                    condition = QUOTE(getMass _target <= 2600 && {alive _target} && {vectorMagnitude velocity _target < 3});
                    statement = QUOTE(_this call FUNC(push));
                    showDisabled = 0;
                    priority = -1;
                };
                class ACE_Passengers {
                    displayName = CSTRING(Passengers);
                    condition = "true";
                    statement = "";
                    insertChildren = QUOTE(_this call DFUNC(addPassengersActions));
                };
				
				class ACE_repair {
					displayName = "$STR_vInAct_Repair";
					distance = 4;
					condition = "alive _target && {speed _target == 0} && {(damage _target < 1)}";
					statement = "[_target] spawn life_fnc_repairTruck";
					showDisabled = 1;
					priority = 1.6;
				};
				class ACE_copRegistration {
					displayName = "$STR_vInAct_Registration";
					distance = 4;
					condition = "alive _target && {speed _target == 0} && {playerSide == west}";
					statement = "[_target] spawn life_fnc_searchVehAction";
					showDisabled = 0;
					priority = 1.6;
				};
                class ACE_copSerchVeh {
					displayName = "$STR_vInAct_SearchVehicle";
					distance = 4;
					condition = "alive _target && {speed _target == 0} && playerSide == west";
					statement = "[_target] spawn life_fnc_vehInvSearch;";
					showDisabled = 0;
					priority = 1.6;
				};
				class ACE_copPullout {
					displayName = "Ejecter";
					distance = 4;
					condition = "alive _target && {speed _target == 0} && {count crew _target != 0} && {playerSide in [west,east]}";
					statement = "[_target] spawn life_fnc_pulloutAction";
					showDisabled = 0;
					priority = 1.6;
				};
				class ACE_Impound {
					displayName = "$STR_vInAct_Impound";
					distance = 4;
					condition = "alive _target && {speed _target == 0} && {playerSide == west}";
					statement = "[_target] spawn life_fnc_impoundAction";
					showDisabled = 0;
					priority = 1.6;
				};
				class ACE_Unflip {
					displayName = "$STR_vInAct_Unflip";
					distance = 4;
					condition = "alive _target && {speed _target == 0} && {!(typeOf (_target) in [""C_Kart_01_Blu_F"",""C_Kart_01_Red_F"",""C_Kart_01_Fuel_F"",""C_Kart_01_Vrana_F""])} && {!(canMove _target)} && {count crew _target == 0}";
					statement = "_target setPos [getPos _target select 0, getPos _target select 1, (getPos _target select 2)+0.5]";
					showDisabled = 0;
					priority = 1.6;
				};
            };
        };

        class ACE_SelfActions {
            class ACE_Passengers {
                displayName = CSTRING(Passengers);
                condition = "true";
                statement = "";
                insertChildren = QUOTE(_this call DFUNC(addPassengersActions));
            };
        };
    };
	
    class StaticWeapon: LandVehicle {
        class ACE_Actions {
            class ACE_MainActions {
                displayName = CSTRING(MainAction);
                selection = "gunnerview";
                distance = 2;
                condition = "true";
                class ACE_Passengers {
                    displayName = CSTRING(Passengers);
                    condition = "true";
                    statement = "";
                    insertChildren = QUOTE(_this call DFUNC(addPassengersActions));
                };
            };
        };

        class ACE_SelfActions {
            class ACE_Passengers {
                displayName = CSTRING(Passengers);
                condition = "true";
                statement = "";
                insertChildren = QUOTE(_this call DFUNC(addPassengersActions));
            };
        };
    };

    class Pod_Heli_Transport_04_base_F: StaticWeapon {
        class ACE_Actions: ACE_Actions {
            class ACE_MainActions: ACE_MainActions {
                distance = 5;
            };
        };
    };

    class StaticMGWeapon: StaticWeapon {};
    class HMG_01_base_F: StaticMGWeapon {};

    class HMG_01_high_base_F: HMG_01_base_F {
        class ACE_Actions: ACE_Actions {
            class ACE_MainActions: ACE_MainActions {
                position = "[-0.172852,0.164063,-0.476091]";
            };
        };
    };

    class AA_01_base_F: StaticMGWeapon {
        class ACE_Actions: ACE_Actions {
            class ACE_MainActions: ACE_MainActions {
                position = "[0,0.515869,-0.200671]";
            };
        };
    };

    class AT_01_base_F: StaticMGWeapon {
        class ACE_Actions: ACE_Actions {
            class ACE_MainActions: ACE_MainActions {
                position = "[0,0.515869,-0.200671]";
            };
        };
    };

    class ThingX;
    class ReammoBox_F: ThingX {
        class ACE_Actions {
            class ACE_MainActions {
                displayName = CSTRING(MainAction);
                selection = "";
                distance = 2;
                condition = "true";

                class ACE_OpenBox {
                    displayName = CSTRING(OpenBox);
                    condition = QUOTE(alive _target);
                    statement = QUOTE(_player action [ARR_2(QUOTE(QUOTE(Gear)), _target)]);
                    showDisabled = 0;
                    priority = -1;
                };
            };
        };

        class ACE_SelfActions {};
    };

    class ACE_RepairItem_Base: ThingX {
        class ACE_Actions {
            class ACE_MainActions {
                displayName = CSTRING(MainAction);
                selection = "";
                distance = 2;
                condition = "true";
            };
        };

        class ACE_SelfActions {};
    };

    class Lamps_base_F;
    class Land_PortableLight_single_F: Lamps_base_F {
        class EventHandlers {
            class CBA_Extended_EventHandlers: CBA_Extended_EventHandlers {};
        };

        scope = 2;
        class ACE_Actions {
            class ACE_MainActions {
                displayName = CSTRING(MainAction);
                selection = "";
                distance = 2;
                condition = "true";
                class ACE_LampTurnOn {
                    displayName = CSTRING(TurnOn);
                    condition = QUOTE(alive _target && !(_target getVariable [ARR_2('ACE_lampOn',true)]));
                    statement = QUOTE(_target call DFUNC(switchLamp));
                    selection = "";
                    distance = 2;
                };
                class ACE_LampTurnOff {
                    displayName = CSTRING(TurnOff);
                    condition = QUOTE(alive _target && _target getVariable [ARR_2('ACE_lampOn',true)]);
                    statement = QUOTE(_target call DFUNC(switchLamp));
                    selection = "";
                    distance = 2;
                };
            };
        };
    };
    class Land_PortableLight_single_off_F: Land_PortableLight_single_F {
        scope = 1;
    };
    class Land_PortableLight_double_F: Land_PortableLight_single_F {};
    class Land_PortableLight_double_off_F: Land_PortableLight_double_F {
        scope = 1;
    };
    
    class RoadCone_F: ThingX {
        class ACE_Actions {
            class ACE_MainActions {
                displayName = CSTRING(MainAction);
                selection = "";
                distance = 2;
                condition = "true";
            };
        };
    };

    class RoadBarrier_F: RoadCone_F {
        class ACE_Actions: ACE_Actions {
            class ACE_MainActions: ACE_MainActions {
                position = "[0,0,0.500671]";
            };
        };
    };
};
