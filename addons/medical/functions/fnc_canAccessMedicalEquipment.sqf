/*
 * Author: Glowbal
 * Check if caller can access targets medical equipment, based upon accessLevel.
 *
 * Arguments:
 * 0: The caller <OBJECT>
 * 1: The target <OBJECT>
 *
 * ReturnValue:
 * Can Treat <BOOL>
 *
 * Public: Yes
 */

#include "script_component.hpp"

private ["_accessLevel", "_return"];
params ["_caller", "_target"];

_accessLevel = _target getVariable [QGVAR(allowSharedEquipmentAccess), -1];

_return = false;
_return = switch (true) do
{
	case (side _caller == side _target && side _caller != civilian):
	{
		true;
	};

	case (side _caller == independent): {true;};

	default
	{
		false;
	};
};

_return;
