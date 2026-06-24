#include <windows.h>
#include <iostream>

std::string obtenerResolucion()
{
    DEVMODE dv;
    ZeroMemory(&dv, sizeof(dv));
    dv.dmSize = sizeof(dv);
    if (EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, &dv))
    {
        return dv.dmPelsWidth + "x" + dv.dmPelsHeight;
    }
    return "No se pudo obtener la informacion";
}