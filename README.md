# SA-MP Time Plugin (Linux)

A lightweight SA-MP server plugin for Linux that provides real-time system clock access and displays it in-game using TextDraw.

## Features

* Retrieves server time directly from the host system
* Provides a custom Pawn native: `GetServerTime()`
* Outputs time in HH:MM:SS format
* Minimal and efficient implementation
* Designed for Linux SA-MP servers (32-bit)

---

## Usage

Include the plugin in your Pawn script:

```pawn
#include <timeplugin>
```

### Native

```pawn
native GetServerTime();
```

### Example

```pawn
new time = GetServerTime();

new hour = (time >> 16) & 0xFF;
new minute = (time >> 8) & 0xFF;
new second = time & 0xFF;
```

---

## TextDraw Example

```pawn
new Text:TimeTD;

public OnGameModeInit()
{
    TimeTD = TextDrawCreate(10.0, 430.0, "Time: 00:00:00");
    TextDrawFont(TimeTD, 1);
    TextDrawLetterSize(TimeTD, 0.3, 1.0);
    TextDrawColor(TimeTD, 0xFFFFFFFF);
    TextDrawSetOutline(TimeTD, 1);
    TextDrawSetProportional(TimeTD, 1);
    TextDrawSetShadow(TimeTD, 1);

    SetTimer("UpdateTimeTD", 1000, true);
    return 1;
}

forward UpdateTimeTD();
public UpdateTimeTD()
{
    new time = GetServerTime();

    new hour = (time >> 16) & 0xFF;
    new minute = (time >> 8) & 0xFF;
    new second = time & 0xFF;

    new str[32];
    format(str, sizeof(str), "Time: %02d:%02d:%02d", hour, minute, second);

    TextDrawSetString(TimeTD, str);
    TextDrawShowForAll(TimeTD);

    return 1;
}
```

---

## Project Structure

```
/plugins/timeplugin.so
/pawno/include/timeplugin.inc
/gamemodes/gamemode.amx
```

---

## Notes

* Compiled as a 32-bit `.so` plugin for Linux SA-MP servers
* Uses system time from the host machine
* AMX-related warnings during compilation are normal and safe to ignore

---

## License

Open-source and free to use. Modification and redistribution are allowed.

---

## Credits

* SA-MP Team
* samp-plugin-sdk by Zeex
