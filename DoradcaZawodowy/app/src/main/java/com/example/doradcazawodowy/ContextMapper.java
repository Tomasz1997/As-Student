package com.example.doradcazawodowy;

import android.content.Context;

import java.util.HashMap;
import java.util.Map;

public class ContextMapper {
    public Map<String, Personality> PersonalityMap = new HashMap<String, Personality>();
    public Map<String, Activity> ActivityMap = new HashMap<String, Activity>();
    public Map<String, RadioSetter> RadioSetterMap = new HashMap<String, RadioSetter>();

    public ContextMapper(Context context)
    {
        PersonalityMap.put(((android.app.Activity)context).getResources().getString(R.string.notSelected), Personality.notSelected);
        PersonalityMap.put(((android.app.Activity)context).getResources().getString(R.string.extrovert), Personality.extrovert);
        PersonalityMap.put(((android.app.Activity)context).getResources().getString(R.string.introvert), Personality.introvert);
        PersonalityMap.put(((android.app.Activity)context).getResources().getString(R.string.ambivalent), Personality.ambivalent);

        ActivityMap.put(((android.app.Activity)context).getResources().getString(R.string.notSelected), Activity.notSelected);
        ActivityMap.put(((android.app.Activity)context).getResources().getString(R.string.physical), Activity.physical);
        ActivityMap.put(((android.app.Activity)context).getResources().getString(R.string.mental), Activity.mental);
        ActivityMap.put(((android.app.Activity)context).getResources().getString(R.string.noMatter), Activity.noMatter);

        RadioSetterMap.put(((android.app.Activity)context).getResources().getString(R.string.confirm), RadioSetter.yes);
        RadioSetterMap.put(((android.app.Activity)context).getResources().getString(R.string.deny), RadioSetter.no);
        RadioSetterMap.put(((android.app.Activity)context).getResources().getString(R.string.irrelevant), RadioSetter.noMatter);
    }
}
