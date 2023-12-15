Action()
{
	lr_save_string("GET_freetogame","Transaction_Name");
	lr_start_transaction(lr_eval_string("{Transaction_Name}"));
	
	web_reg_find("Text/IC=status",LAST);
	
	//Correlated Values might needed in next POST or UPDATE request
	web_reg_save_param_json("ParamName=LR_id","QueryString=$.id",SEARCH_FILTERS,"Scope=Body","LAST");
	web_reg_save_param_json("ParamName=LR_title","QueryString=$.title",SEARCH_FILTERS,"Scope=Body","LAST");
	web_reg_save_param_json("ParamName=LR_thumbnail","QueryString=$.thumbnail",SEARCH_FILTERS,"Scope=Body","LAST");
	web_reg_save_param_json("ParamName=LR_status","QueryString=$.status",SEARCH_FILTERS,"Scope=Body","LAST");
	web_reg_save_param_json("ParamName=LR_short_description","QueryString=$.short_description",SEARCH_FILTERS,"Scope=Body","LAST");
	web_reg_save_param_json("ParamName=LR_description","QueryString=$.description",SEARCH_FILTERS,"Scope=Body","LAST");
	web_reg_save_param_json("ParamName=LR_game_url","QueryString=$.game_url",SEARCH_FILTERS,"Scope=Body","LAST");	
	web_reg_save_param_json("ParamName=LR_genre","QueryString=$.genre",SEARCH_FILTERS,"Scope=Body","LAST");
	web_reg_save_param_json("ParamName=LR_platform","QueryString=$.platform",SEARCH_FILTERS,"Scope=Body","LAST");
	web_reg_save_param_json("ParamName=LR_publisher","QueryString=$.publisher",SEARCH_FILTERS,"Scope=Body","LAST");
	web_reg_save_param_json("ParamName=LR_developer","QueryString=$.developer",SEARCH_FILTERS,"Scope=Body","LAST");
	web_reg_save_param_json("ParamName=LR_release_date","QueryString=$.release_date",SEARCH_FILTERS,"Scope=Body","LAST");
	web_reg_save_param_json("ParamName=LR_freetogame_profile_url","QueryString=$.freetogame_profile_url",SEARCH_FILTERS,"Scope=Body","LAST");
	web_reg_save_param_json("ParamName=LR_screenshots","QueryString=$.screenshots",SEARCH_FILTERS,"Scope=Body","LAST");
	
	
	
	

	web_custom_request("freetogame",
		 "URL=https://www.freetogame.com/api/game?id={TD_Id}",
		 "Method=GET",
		 "Resource=0",
		 "RecContentType=text/html",
		 "Referer=https://www.freetogame.com/api/game?id=455",
		 "Snapshot=t23.inf",
		 "Mode=HTTP",
		 LAST);
	
	lr_end_transaction(lr_eval_string("{Transaction_Name}"),LR_AUTO);
	
	return 0;
}
