package com.example.doradcazawodowy;

import android.content.Context;
import android.content.res.Resources;
import android.widget.RadioGroup;
import android.widget.Spinner;
import android.widget.TextView;

public class CareerOption {
    Personality personality;
    Activity activity;
    RadioSetter repeatable;
    RadioSetter challenge;
    RadioSetter creativity;

    public CareerOption(Personality personality, Activity activity, RadioSetter repeatable, RadioSetter challenge, RadioSetter creativity) {
        this.personality = personality;
        this.activity = activity;
        this.repeatable = repeatable;
        this.challenge = challenge;
        this.creativity = creativity;
    }

    public CareerOption(Context context, Spinner personality, Spinner activity, RadioGroup repeatable, RadioGroup challenge, RadioGroup creativity) {
        ContextMapper contextMapper = new ContextMapper(context);

        this.personality = contextMapper.PersonalityMap.get(String.valueOf(personality.getSelectedItem()));
        this.activity = contextMapper.ActivityMap.get(String.valueOf(activity.getSelectedItem()));
        this.repeatable = contextMapper.RadioSetterMap.get(((TextView) ((android.app.Activity) context).findViewById(repeatable.getCheckedRadioButtonId())).getText().toString());
        this.challenge = contextMapper.RadioSetterMap.get(((TextView) ((android.app.Activity) context).findViewById(challenge.getCheckedRadioButtonId())).getText().toString());
        this.creativity = contextMapper.RadioSetterMap.get(((TextView) ((android.app.Activity) context).findViewById(creativity.getCheckedRadioButtonId())).getText().toString());
    }

    @Override
    public boolean equals(Object o) {
        if (o == this) return true;

        if (!(o instanceof CareerOption)) return false;

        CareerOption toCompare = (CareerOption) o;

        return (this.personality == toCompare.personality || this.personality.isNotImportantFor(toCompare.personality)) &&
                (this.activity == toCompare.activity || this.activity.isNotImportantFor(toCompare.activity)) &&
                (this.repeatable == toCompare.repeatable || this.repeatable.isNotImportantFor(toCompare.repeatable)) &&
                (this.challenge == toCompare.challenge || this.challenge.isNotImportantFor(toCompare.challenge)) &&
                (this.creativity == toCompare.creativity || this.creativity.isNotImportantFor(toCompare.creativity));
    }
}
