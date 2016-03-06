
class CfgVehicles {
	class ACE_Module;
	class ACE_ModuleInteraction : ACE_Module {
		author = "$STR_ace_common_ACETeam";
		category = ACE;
		displayName = "$STR_ace_interaction_Module_DisplayName";
		function = "ACE_Interaction_fnc_moduleInteraction";
		scope = public;
		isGlobal = 1;
		isSingular = 1;
		icon = "\z\ace\addons\interaction\UI\Icon_Module_Interaction_ca.paa";
		
		class Arguments {
			class EnableTeamManagement {
				displayName = "$STR_ace_interaction_EnableTeamManagement_DisplayName";
				description = "$STR_ace_interaction_EnableTeamManagement_Description";
				typeName = BOOL;
				defaultValue = 1;
			};
		};
		
		class ModuleDescription {
			description = "$STR_ace_interaction_Module_Description";
		};
	};
	
	class Man;
	class CAManBase : Man {
		class ACE_Actions {
			class ACE_MainActions {
				displayName = "$STR_ace_interaction_MainAction";
				distance = 4;
				condition = 1;
				statement = "";
				icon = "\a3\ui_f\data\IGUI\Cfg\Actions\eject_ca.paa";
				selection = "pelvis";
				
				class ACE_PassMagazine {
					displayName = "$STR_ace_interaction_PassMagazine";
					condition = "";
					statement = "";
					showDisabled = 0;
					priority = 3.3;
					icon = "\a3\ui_f\data\gui\Rsc\RscDisplayArsenal\cargomag_ca.paa";
					
					class ACE_PassMagazinePrimary {
						displayName = "$STR_ace_interaction_PassMagazinePrimary";
						condition = "[_player,_target,primaryWeapon _target] call ace_interaction_fnc_canPassMagazine";
						statement = "[_player,_target,primaryWeapon _target] call ace_interaction_fnc_passMagazine";
						showDisabled = 0;
						priority = 3;
						icon = "\a3\ui_f\data\gui\Rsc\RscDisplayArsenal\primaryweapon_ca.paa";
					};
					
					class ACE_PassMagazineHandgun {
						displayName = "$STR_ace_interaction_PassMagazineHandgun";
						condition = "[_player,_target,handgunWeapon _target] call ace_interaction_fnc_canPassMagazine";
						statement = "[_player,_target,handgunWeapon _target] call ace_interaction_fnc_passMagazine";
						showDisabled = 0;
						priority = 1;
						icon = "\a3\ui_f\data\gui\Rsc\RscDisplayArsenal\handgun_ca.paa";
					};
				};
				
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
						statement = "[] call life_fnc_showArrestDialog;";
						showDisabled = 1;
						priority = 2.5;
						hotkey = "P";
					};
				};
				
				class ACE_Armyinteraction {
					displayName = "Interaction armée";
					distance = 4;
					condition = "(alive _target) && {isPlayer _target} && {_target isKindOf 'Man'} && {(_target getVariable['ACE_Captives_isHandcuffed',false]) OR (_target getVariable['ACE_Captives_isSurrendering',false])} && {playerSide == east} && {side _target in [civilian,independent]}";
					statement = "";
					showDisabled = 0;
					priority = 3.2;
					subMenu[] = {"ACE_Armyinteraction",0};
					hotkey = "C";
					class ACE_TakeUniform {
						displayName = "Saisir vetements";
						distance = 4;
						condition = "alive _target && {isPlayer _target} && {_target isKindOf 'Man'} && {(_target getVariable['ACE_Captives_isHandcuffed',false])} && {playerSide == east} && {side _target in [civilian,independent]}";
						statement = "[_target] spawn life_fnc_takeUniform;";
						showDisabled = 1;
						priority = 2.4;
						hotkey = "V";
					};
					class ACE_TakeWeapons {
						displayName = "Saisir armes";
						distance = 4;
						condition = "alive _target && {isPlayer _target} && {_target isKindOf 'Man'} && {(_target getVariable['ACE_Captives_isHandcuffed',false])} && {playerSide == east} && {side _target in [civilian,independent]}";
						statement = "[_target] spawn life_fnc_takeWeapons;";
						showDisabled = 1;
						priority = 2.4;
						hotkey = "A";
					};
				};
			};
			
			class ACE_Torso {
				displayName = "$STR_ace_interaction_Torso";
				selection = "spine3";
				distance = 1.5;
				condition = "";
				statement = "";
			};
			
			class ACE_Head {
				displayName = "$STR_ace_interaction_Head";
				selection = "pilot";
				distance = 1.5;
				condition = "";
				statement = "";
			};
			
			class ACE_ArmLeft {
				displayName = "$STR_ace_interaction_ArmLeft";
				selection = "LeftForeArm";
				distance = 1.5;
				condition = "";
				statement = "";
			};
			
			class ACE_ArmRight {
				displayName = "$STR_ace_interaction_ArmRight";
				selection = "RightForeArm";
				distance = 1.5;
				condition = "";
				statement = "";
			};
			
			class ACE_LegLeft {
				displayName = "$STR_ace_interaction_LegLeft";
				selection = "LKnee";
				distance = 1.5;
				condition = "";
				statement = "";
			};
			
			class ACE_LegRight {
				displayName = "$STR_ace_interaction_LegRight";
				selection = "RKnee";
				distance = 1.5;
				condition = "";
				statement = "";
			};
			
			class ACE_Weapon {
				displayName = "$STR_ace_interaction_Weapon";
				position = "call ace_interaction_fnc_getWeaponPos";
				distance = 1.5;
				condition = "";
				statement = "";
			};
		};
		
		class ACE_SelfActions {
			class ACE_Equipment {
				displayName = "$STR_ace_interaction_Equipment";
				condition = 1;
				exceptions[] = {"isNotInside", "notOnMap", "isNotSitting"};
				statement = "";
				showDisabled = 1;
				priority = 4.5;
				icon = "";
			};
		};
	};
	
	class LandVehicle;
	class Car : LandVehicle {
		class ACE_Actions {
			class ACE_MainActions {
				displayName = "$STR_ace_interaction_MainAction";
				selection = "";
				distance = 10;
				condition = 1;
				
				class ACE_Passengers {
					displayName = "$STR_ace_interaction_Passengers";
					condition = 1;
					statement = "";
					insertChildren = "_this call ace_interaction_fnc_addPassengersActions";
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
					condition = "alive _target && {speed _target == 0} && playerSide == west";
					statement = "[_target] spawn life_fnc_searchVehAction";
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
				displayName = "$STR_ace_interaction_Passengers";
				condition = 1;
				statement = "";
				insertChildren = "_this call ace_interaction_fnc_addPassengersActions";
			};
		};
	};
	class Tank : LandVehicle {
		class ACE_Actions {
			class ACE_MainActions {
				displayName = "$STR_ace_interaction_MainAction";
				selection = "";
				distance = 10;
				condition = 1;
				
				class ACE_Passengers {
					displayName = "$STR_ace_interaction_Passengers";
					condition = 1;
					statement = "";
					insertChildren = "_this call ace_interaction_fnc_addPassengersActions";
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
				displayName = "$STR_ace_interaction_Passengers";
				condition = 1;
				statement = "";
				insertChildren = "_this call ace_interaction_fnc_addPassengersActions";
			};
		};
	};
	
	class Air;
	class Helicopter : Air {
		class ACE_Actions {
			class ACE_MainActions {
				displayName = "$STR_ace_interaction_MainAction";
				selection = "";
				distance = 10;
				condition = 1;
				
				class ACE_Passengers {
					displayName = "$STR_ace_interaction_Passengers";
					condition = 1;
					statement = "";
					insertChildren = "_this call ace_interaction_fnc_addPassengersActions";
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
					condition = "alive _target && {speed _target == 0} && {(playerSide in [west,Independent])}";
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
				displayName = "$STR_ace_interaction_Passengers";
				condition = 1;
				statement = "";
				insertChildren = "_this call ace_interaction_fnc_addPassengersActions";
			};
		};
	};
	class Plane : Air {
		class ACE_Actions {
			class ACE_MainActions {
				displayName = "$STR_ace_interaction_MainAction";
				selection = "";
				distance = 10;
				condition = 1;
				
				class ACE_Passengers {
					displayName = "$STR_ace_interaction_Passengers";
					condition = 1;
					statement = "";
					insertChildren = "_this call ace_interaction_fnc_addPassengersActions";
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
				displayName = "$STR_ace_interaction_Passengers";
				condition = 1;
				statement = "";
				insertChildren = "_this call ace_interaction_fnc_addPassengersActions";
			};
		};
	};
	
	class Ship;	
	class Ship_F : Ship {
		class ACE_Actions {
			class ACE_MainActions {
				displayName = "$STR_ace_interaction_MainAction";
				selection = "";
				distance = 10;
				condition = 1;
				
				class ACE_Push {
					displayName = "$STR_ace_interaction_Push";
					distance = 6;
					condition = "getMass _target <= 2600 && {alive _target} && {vectorMagnitude velocity _target < 3}";
					statement = "_this call ace_interaction_fnc_push";
					showDisabled = 0;
					priority = -1;
				};
				
				class ACE_Passengers {
					displayName = "$STR_ace_interaction_Passengers";
					condition = 1;
					statement = "";
					insertChildren = "_this call ace_interaction_fnc_addPassengersActions";
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
				displayName = "$STR_ace_interaction_Passengers";
				condition = 1;
				statement = "";
				insertChildren = "_this call ace_interaction_fnc_addPassengersActions";
			};
		};
	};
	
	class StaticWeapon : LandVehicle {
		class ACE_Actions {
			class ACE_MainActions {
				displayName = "$STR_ace_interaction_MainAction";
				selection = "gunnerview";
				distance = 2;
				condition = 1;
				
				class ACE_Passengers {
					displayName = "$STR_ace_interaction_Passengers";
					condition = 1;
					statement = "";
					insertChildren = "_this call ace_interaction_fnc_addPassengersActions";
				};
			};
		};
		
		class ACE_SelfActions {
			class ACE_Passengers {
				displayName = "$STR_ace_interaction_Passengers";
				condition = 1;
				statement = "";
				insertChildren = "_this call ace_interaction_fnc_addPassengersActions";
			};
		};
	};
	
	class Pod_Heli_Transport_04_base_F : StaticWeapon {
		class ACE_Actions : ACE_Actions {
			class ACE_MainActions : ACE_MainActions {
				distance = 5;
			};
		};
	};
	
	class StaticMGWeapon : StaticWeapon {};
	
	class HMG_01_base_F : StaticMGWeapon {};
	
	class HMG_01_high_base_F : HMG_01_base_F {
		class ACE_Actions : ACE_Actions {
			class ACE_MainActions : ACE_MainActions {
				position = "[-0.172852,0.164063,-0.476091]";
			};
		};
	};
	
	class AA_01_base_F : StaticMGWeapon {
		class ACE_Actions : ACE_Actions {
			class ACE_MainActions : ACE_MainActions {
				position = "[0,0.515869,-0.200671]";
			};
		};
	};
	
	class AT_01_base_F : StaticMGWeapon {
		class ACE_Actions : ACE_Actions {
			class ACE_MainActions : ACE_MainActions {
				position = "[0,0.515869,-0.200671]";
			};
		};
	};
	
	class ThingX;	// External class reference	
	class ReammoBox_F : ThingX {
		class ACE_Actions {
			class ACE_MainActions {
				displayName = "$STR_ace_interaction_MainAction";
				selection = "";
				distance = 2;
				condition = 1;
				
				class ACE_OpenBox {
					displayName = "$STR_ace_interaction_OpenBox";
					condition = "alive _target";
					statement = "_player action [""Gear"",_target]";
					showDisabled = 0;
					priority = -1;
				};
			};
		};
		
		class ACE_SelfActions {};
	};
	
	class ACE_RepairItem_Base : ThingX {
		class ACE_Actions {
			class ACE_MainActions {
				displayName = "$STR_ace_interaction_MainAction";
				selection = "";
				distance = 2;
				condition = 1;
			};
		};
		
		class ACE_SelfActions {};
	};
	
	class RoadCone_F : ThingX {
		class ACE_Actions {
			class ACE_MainActions {
				displayName = "$STR_ace_interaction_MainAction";
				selection = "";
				distance = 2;
				condition = 1;
			};
		};
	};
	
	class RoadBarrier_F : RoadCone_F {
		class ACE_Actions : ACE_Actions {
			class ACE_MainActions : ACE_MainActions {
				position = "[0,0,0.500671]";
			};
		};
	};
};
