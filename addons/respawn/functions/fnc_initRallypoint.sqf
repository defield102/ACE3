/*
  Name: ACE_Respawn_fnc_initRallypoint
  
  Author(s):
    commy2
  
  Description:
    init code for rally points
  
  Parameters:
    0: OBJECT - rally
  
  Returns:
    VOID
*/

#include "script_component.hpp"

private ["_rallypoint", "_respawnMarker", "_side"];

_rallypoint = _this select 0;
_respawnMarker = _this select 1;
_side = _this select 2;

private "_name";
_name = typeOf _rallypoint;

// init visible marker
if (hasInterface) then {
    private ["_marker", "_type"];

    _marker = format ["ACE_Marker_%1", _name];

    // exit if it already exist
    if (_marker in allMapMarkers) exitWith {};

    _marker = createMarkerLocal [_marker, getPosASL _rallypoint];
    _type = ["selector_selectedFriendly", "selector_selectedEnemy"] select (_respawnMarker == "");

    _marker setMarkerTypeLocal _type;
    _marker setMarkerAlphaLocal ([0,1] select (_side == playerSide));  // playerSide to guarantee init

    private "_markerDate";
    _markerDate = _rallypoint getVariable [QGVAR(markerDate), ""];

    _marker setMarkerTextLocal _markerDate;

    _rallypoint setVariable [QGVAR(marker), _marker];
};

if (!isServer) exitWith {};

if (isNil _name) then {
    missionNamespace setVariable [_name, _rallypoint];
    publicVariable _name;

    _rallypoint setVariable [QGVAR(side), _side, true];

    if (_respawnMarker != "" && {!(_respawnMarker in allMapMarkers)}) then {
        createMarker [_respawnMarker, _rallypoint];
    };

    ["rallypointMoved", [_rallypoint, _side]] call EFUNC(common,globalEvent);

} else {
    deleteVehicle _rallypoint;
    diag_log text "[ACE] Respawn: ERROR Multiple Rallypoints of same type.";
};
