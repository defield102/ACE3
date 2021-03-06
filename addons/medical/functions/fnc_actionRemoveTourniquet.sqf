/*
 * Author: Glowbal
 * Action for removing the tourniquet on specified selection
 *
 * Arguments:
 * 0: The medic <OBJECT>
 * 1: The patient <OBJECT>
 * 2: SelectionName <STRING>
 *
 * Return Value:
 * None
 *
 * Public: Yes
 */

#include "script_component.hpp"

private ["_part", "_tourniquets", "_output"];
params ["_caller", "_target", "_selectionName"];
TRACE_3("params",_caller,_target,_selectionName);

// grab the required data
_part = [_selectionName] call FUNC(selectionNameToNumber);
_tourniquets = _target getVariable [QGVAR(tourniquets), [0,0,0,0,0,0]];

// Check if there is a tourniquet on this bodypart
if ((_tourniquets select _part) == 0) exitWith {
    _output = LSTRING(noTourniquetOnBodyPart);
    ["displayTextStructured", [_caller], [_output, 1.5, _caller]] call EFUNC(common,targetEvent);
};

// Removing the tourniquet
_tourniquets set[_part, 0];
_target setVariable [QGVAR(tourniquets), _tourniquets, true];

// Adding the tourniquet item to the caller
_caller addItem "ACE_tourniquet";

//Handle all injected medications now that blood is flowing:
private _delayedMedications = _target getVariable [QGVAR(occludedMedications), []];
private _updatedArray = false;
TRACE_2("meds",_part,_delayedMedications);
{
    _x params ["", "", "_medPartNum"];
    if (_part == _medPartNum) then {
        TRACE_1("delayed medication call after tourniquet removeal",_x);
        ["treatmentAdvanced_medicationLocal", [_target], _x] call EFUNC(common,targetEvent);
        _delayedMedications set [_forEachIndex, -1];
        _updatedArray = true;
    };
} forEach _delayedMedications;
if (_updatedArray) then {
    _delayedMedications = _delayedMedications - [-1];
    _target setVariable [QGVAR(occludedMedications), _delayedMedications, true];
};
