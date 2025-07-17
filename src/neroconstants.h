/*  Nero Launcher: A very basic Bottles-like manager using UMU.
    Common constants.

    Copyright (C) 2024 That One Seong

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef NEROCONSTANTS_H
#define NEROCONSTANTS_H

class NeroConstant
{
public:
    NeroConstant();

    // TODO: settings should also have associated maps
    // so the ini can use human readable strings that are version-agnostic

    static enum {
        WinVer2dot0 = 0,
        WinVer3dot0,
        WinVer3dot1,
        WinVerNT351,
        WinVerNT400,
        WinVer95,
        WinVer98,
        WinVerME,
        WinVer2000,
        WinVerXP,
        WinVerXP64,
        WinVer2003,
        WinVerVista,
        WinVer2008,
        WinVer7,
        WinVer2008r2,
        WinVer8,
        WinVer8dot1,
        WinVer10,
        WinVerCancer
    } WinVers_e;

    static enum {
        ScalingNormal = 0,
        ScalingIntegerScale,
        ScalingFSRperformance,
        ScalingFSRbalanced,
        ScalingFSRquality,
        ScalingFSRhighquality,
        ScalingFSRhigherquality,
        ScalingFSRhighestquality,
        ScalingFSRcustom,
        ScalingGamescopeWindowed,
        ScalingGamescopeBorderless,
        ScalingGamescopeFullscreen
    } ScalingModes_e;

    static enum {
        GSscalerAuto = 0,
        GSscalerInteger,
        GSscalerFit,
        GSscalerFill,
        GSscalerStretch
    } GamescopeScalers_e;

    static enum {
        GSfilterLinear = 0,
        GSfilterNearest,
        GSfilterFSR,
        GSfilterNLS,
        GSfilterPixel
    } GamescopeFilters_e;

    static enum {
        DebugDisabled = 0,
        DebugLoadDLL,
        DebugFull
    } DebugOutputModes_e;

    static enum {
        NTsync = 0,
        Fsync,
        Esync,
        NoSync
    } FileSyncModes_e;

    static enum {
        DLLNativeThenBuiltin = 0,
        DLLBuiltinOnly,
        DLLBuiltinThenNative,
        DLLNativeOnly,
        DLLDisabled
    } DLLoverrideTypes_e;
};

#endif // NEROCONSTANTS_H
