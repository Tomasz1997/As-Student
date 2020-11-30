package com.example.doradcazawodowy;

import android.app.Activity;
import android.content.Context;
import android.view.View;
import android.widget.TextView;

public class ErrorMessage
{
    TextView errorMessage;

    public ErrorMessage(Context context)
    {
        errorMessage = (TextView) ((Activity)context).findViewById(R.id.errorMessage);
    }

    public void show()
    {
        errorMessage.setVisibility(View.VISIBLE);
    }

    public void hide()
    {
        errorMessage.setVisibility(View.GONE);
    }
}
