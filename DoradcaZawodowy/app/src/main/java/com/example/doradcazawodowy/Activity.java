package com.example.doradcazawodowy;

public enum  Activity
{
    notSelected,
    physical,
    mental,
    noMatter;

    public boolean isNotImportantFor(Activity other)
    {
        if(this == Activity.noMatter) return true;

        if(other == Activity.noMatter) return true;

        return false;
    }
}
