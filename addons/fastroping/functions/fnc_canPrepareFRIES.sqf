/*
 * Author: BaerMitUmlaut
 * Checks if the unit can prepare the helicopters FRIES.
 *
 * Arguments:
 * 0: The helicopter itself <OBJECT>
 *
 * Return Value:
 * Able to prepare FRIES <BOOL>
 *
 * Example:
 * [_vehicle] call ace_fastroping_fnc_canPrepareFRIES
 *
 * Public: No
 */

#include "script_component.hpp"
params ["_vehicle"];

private _config = configFile >> "CfgVehicles" >> typeOf _vehicle;

(isNumber (_config >> QGVAR(enabled)) &&
{(getNumber (_config >> QGVAR(enabled)) == 1) || {!(isNull (_vehicle getVariable [QGVAR(FRIES), objNull]))}} &&
{(_vehicle getVariable [QGVAR(deploymentStage), 0]) == 0} &&
{isText (_config >> QGVAR(onPrepare))})
