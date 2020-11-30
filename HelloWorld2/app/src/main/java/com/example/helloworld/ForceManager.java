package com.example.helloworld;

public class ForceManager {

    public static String getWelcomePromptWithName(String welcomeSubtitle, String name)
    {
       if(name.isEmpty()) return welcomeSubtitle;
       else return welcomeSubtitle + ", " + name;
    }
}
