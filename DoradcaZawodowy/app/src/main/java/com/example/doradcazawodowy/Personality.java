package com.example.doradcazawodowy;

public enum Personality
{
    notSelected,
    extrovert,
    introvert,
    ambivalent;

    public boolean isNotImportantFor(Personality other)
    {
        if(this == Personality.ambivalent) return true;

        if(other == Personality.ambivalent) return true;

        return false;
    }
}
