/*
 * Author: Jonpas
 * Checks if unit can check fuel.
 *
 * Arguments:
 * 0: Unit <OBJECT>
 * 1: Target <OBJECT>
 *
 * Return Value:
 * Can Check Fuel <BOOL>
 *
 * Example:
 * [unit, target] call ace_refuel_fnc_canCheckFuel
 *
 * Public: No
 */
#include "script_component.hpp"

params ["_unit", "_target"];

if (isNull _unit || {!(_unit isKindOf "CAManBase")} || {!local _unit} || {(_target distance _unit) > REFUEL_ACTION_DISTANCE}) exitWith {false};

true
