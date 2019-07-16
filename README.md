# ReverseNX
SaltyNX plugin forcing docked or handheld graphics settings

For now in experimental phase, because it looks like SaltyNX is not in good terms with some games (they will crash without any plugin).

-----------

Flags:
create in folder `saltynx/plugins/ReverseNX/` empty file:
- `docked.flag` for docked mode

or

- `handheld.flag` for handheld mode 

When both flags are there or none of them, plugin will ignore loading.

For docked mode is recommended to use OC settings exactly as used in docked mode:

>handheld_charging_gpu=768
>
>handheld_charging_mem=1600

[Confirmed games working or not](gameslist.md)

-----------

Known issues:

- Instability with some homebrew

- SaltyNX is still under development, so it may cause issues on it's own. Different versions of game can behave diversely (f.e. Octopath Traveler)

Thanks to 

**shinyquagsire23** for *SaltyNX*

https://github.com/shinyquagsire23/SaltyNX

**ultimate-research** for *code-mod-framework*

https://github.com/ultimate-research/code-mod-framework

**jugeeya** for precompiled SaltyNX nsp sysmodule. Originally it's compiled as kip (precompiled sysmodule only in release)
https://github.com/jugeeya/UltimateTrainingModpack/releases/tag/1.1



How to compile plugin

https://github.com/ultimate-research/code-mod-framework/wiki/Environment-Setup:-Getting-Started

It still works even with errors about not converting unsigned integers properly. Dunno how to repair it.
