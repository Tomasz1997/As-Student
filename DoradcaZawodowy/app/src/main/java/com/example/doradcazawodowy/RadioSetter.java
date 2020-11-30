package com.example.doradcazawodowy;

public enum RadioSetter
{
    yes,
    no,
    noMatter;

    public boolean isNotImportantFor(RadioSetter other)
    {
        if(this == RadioSetter.noMatter) return true;

        if(other == RadioSetter.noMatter) return true;

        return false;
    }
}
