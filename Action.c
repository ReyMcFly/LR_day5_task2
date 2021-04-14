Action()
{



	/* Itinerary */

	web_url("Itinerary Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);
	
//		web_reg_save_param_ex(
//		"ParamName=Price",
//		"LB=name=\"Total Charge: ",
//		"RB=\"",
//		"Ordinary = ALL",
//		LAST);


	web_submit_data("itinerary.pl", 
		"Action=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=1", "Value=on", ENDITEM, 
		"Name=flightID", "Value=1120-788-JB", ENDITEM, 
		"Name=flightID", "Value=1862-1559-JB", ENDITEM, 
		"Name=flightID", "Value=2992-2368-JB", ENDITEM, 
		"Name=.cgifields", "Value=1", ENDITEM, 
		"Name=.cgifields", "Value=3", ENDITEM, 
		"Name=.cgifields", "Value=2", ENDITEM, 
		"Name=removeFlights.x", "Value=63", ENDITEM, 
		"Name=removeFlights.y", "Value=6", ENDITEM, 
		LAST);

	return 0;
}