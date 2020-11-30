package com.example.doradcazawodowy;

import android.app.Activity;
import android.content.Context;
import android.view.View;
import android.widget.RadioGroup;
import android.widget.Spinner;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Iterator;
import java.util.List;
import java.util.ListIterator;
import java.util.stream.Collectors;

public class CareerManager
{
    Spinner personality;
    Spinner activity;
    RadioGroup repeatable;
    RadioGroup challenge;
    RadioGroup creativity;
    Context context;
    List<Career> careers;

    public CareerManager(Context context)
    {
        this.context = context;

        personality = ((Activity)context).findViewById(R.id.selectPersonality);
        activity = ((Activity)context).findViewById(R.id.selectActivity);
        repeatable = ((Activity)context).findViewById(R.id.isReapetable);
        challenge = ((Activity)context).findViewById(R.id.isChallenge);
        creativity = ((Activity)context).findViewById(R.id.isCreativity);

        careers = new ArrayList<Career>();
    }

    public boolean isAllOptionSelected()
    {
        if(String.valueOf(personality.getSelectedItem()) == ((Activity)context).getResources().getString(R.string.notSelected)) return false;
        if(String.valueOf(activity.getSelectedItem()) == ((Activity)context).getResources().getString(R.string.notSelected)) return false;
        if(repeatable.getCheckedRadioButtonId() == -1) return false;
        if(challenge.getCheckedRadioButtonId() == -1) return false;
        if(creativity.getCheckedRadioButtonId() == -1) return false;

        return true;
    }

    public void createDatabaseOfProfession()
    {
        CareerOption option = new CareerOption(Personality.ambivalent, com.example.doradcazawodowy.Activity.physical, RadioSetter.yes, RadioSetter.yes, RadioSetter.no);
        careers.add(new Career(((Activity)context).getResources().getString(R.string.gravedigger), option));

        option = new CareerOption(Personality.ambivalent, com.example.doradcazawodowy.Activity.mental, RadioSetter.yes, RadioSetter.yes, RadioSetter.no);
        careers.add(new Career(((Activity)context).getResources().getString(R.string.doctor), option));

        option = new CareerOption(Personality.extrovert, com.example.doradcazawodowy.Activity.mental, RadioSetter.yes, RadioSetter.yes, RadioSetter.yes);
        careers.add(new Career(((Activity)context).getResources().getString(R.string.lawyer), option));

        option = new CareerOption(Personality.ambivalent, com.example.doradcazawodowy.Activity.physical, RadioSetter.yes, RadioSetter.no, RadioSetter.no);
        careers.add(new Career(((Activity)context).getResources().getString(R.string.bricklayer), option));

        option = new CareerOption(Personality.extrovert, com.example.doradcazawodowy.Activity.mental, RadioSetter.yes, RadioSetter.yes, RadioSetter.yes);
        careers.add(new Career(((Activity)context).getResources().getString(R.string.teacher), option));
    }

    public CareerOption getSelectedOptionByUser()
    {
        return new CareerOption(context, personality, activity, repeatable, challenge, creativity);
    }

    public List<Career> getCareersForUser()
    {
        CareerOption userAnswers = getSelectedOptionByUser();
        createDatabaseOfProfession();

        List<Career> userCareers = careers.stream().filter(career -> userAnswers.equals(career.careerOption)).collect(Collectors.toList());

        return userCareers;
    }
}
