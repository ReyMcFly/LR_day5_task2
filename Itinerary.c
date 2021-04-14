Itinerary()
{
	
	/* Itinerary */
	
	web_reg_save_param_ex(
		"ParamName=Price1",
		"LB=Total Charge: $ ",
		"RB=<BR/>",
		"Ordinal=1",
		LAST);
	
	web_reg_save_param_ex(
		"ParamName=Price2",
		"LB=Total Charge: $ ",
		"RB=<BR/>",
		"Ordinal=2",
		LAST);
		
	web_reg_save_param_ex(
		"ParamName=Price3",
		"LB=Total Charge: $ ",
		"RB=<BR/>",
		"Ordinal=3",
		LAST);
		
	web_reg_save_param_ex(
		"ParamName=ID1",
		"LB=name=\"flightID\" value=\"",
		"RB=\"",
		"Ordinal=1",
		LAST);
		
	web_reg_save_param_ex(
		"ParamName=ID2",
		"LB=name=\"flightID\" value=\"",
		"RB=\"",
		"Ordinal=2",
		LAST);
		
	web_reg_save_param_ex(
		"ParamName=ID3",
		"LB=name=\"flightID\" value=\"",
		"RB=\"",
		"Ordinal=3",
		LAST);		
	
	web_url("Itinerary Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);
	
	if ((atoi(lr_eval_string("{Price1}")) < atoi(lr_eval_string("{Price2}"))) && (atoi(lr_eval_string("{Price1}")) < atoi(lr_eval_string("{Price3}")))) {
	
	minNumber = atoi(lr_eval_string("{Price1}"));
		
	/* Delete */
	/* Cancel Checked */

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
		"Name=flightID", "Value={ID1}", ENDITEM,	
		"Name=flightID", "Value={ID2}", ENDITEM, 
		"Name=flightID", "Value={ID3}", ENDITEM, 
		"Name=.cgifields", "Value=1", ENDITEM, 
		"Name=.cgifields", "Value=3", ENDITEM, 
		"Name=.cgifields", "Value=2", ENDITEM, 
		"Name=removeFlights.x", "Value=56", ENDITEM, 
		"Name=removeFlights.y", "Value=8", ENDITEM, 
		LAST);

	}
		
	else if ((atoi(lr_eval_string("{Price2}")) < atoi(lr_eval_string("{Price1}"))) && (atoi(lr_eval_string("{Price2}")) < atoi(lr_eval_string("{Price3}")))) {
        	
	minNumber = atoi(lr_eval_string("{Price2}"));
        	
    /* Delete */
	/* Cancel Checked */

	web_submit_data("itinerary.pl", 
		"Action=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=flightID", "Value={ID1}", ENDITEM,
		"Name=2", "Value=on", ENDITEM, 		
		"Name=flightID", "Value={ID2}", ENDITEM, 
		"Name=flightID", "Value={ID3}", ENDITEM, 
		"Name=.cgifields", "Value=1", ENDITEM, 
		"Name=.cgifields", "Value=3", ENDITEM, 
		"Name=.cgifields", "Value=2", ENDITEM, 
		"Name=removeFlights.x", "Value=56", ENDITEM, 
		"Name=removeFlights.y", "Value=8", ENDITEM, 
		LAST);
        	
	}
		
	else if ((atoi(lr_eval_string("{Price3}")) < atoi(lr_eval_string("{Price1}"))) && (atoi(lr_eval_string("{Price3}")) < atoi(lr_eval_string("{Price2}")))) {
        
	minNumber = atoi(lr_eval_string("{Price3}"));
        
	/* Delete */
	/* Cancel Checked */

	web_submit_data("itinerary.pl", 
		"Action=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=flightID", "Value={ID1}", ENDITEM, 		
		"Name=flightID", "Value={ID2}", ENDITEM,
		"Name=3", "Value=on", ENDITEM,		
		"Name=flightID", "Value={ID3}", ENDITEM, 
		"Name=.cgifields", "Value=1", ENDITEM, 
		"Name=.cgifields", "Value=3", ENDITEM, 
		"Name=.cgifields", "Value=2", ENDITEM, 
		"Name=removeFlights.x", "Value=56", ENDITEM, 
		"Name=removeFlights.y", "Value=8", ENDITEM, 
		LAST);
	
		}
	
		lr_output_message("MIIIIN %d", minNumber);
	
		lr_output_message("Ticket price: %d", atoi(lr_eval_string("{Price1}")));
		lr_output_message("Ticket price: %d", atoi(lr_eval_string("{Price2}")));
		lr_output_message("Ticket price: %d", atoi(lr_eval_string("{Price3}")));
		
		lr_output_message("ID: %s", (lr_eval_string("{ID1}")));
		lr_output_message("ID: %s", (lr_eval_string("{ID2}")));
		lr_output_message("ID: %s", (lr_eval_string("{ID3}")));

	return 0;
}