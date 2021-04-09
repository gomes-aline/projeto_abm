
EQUATION("Initialization_2")

consumption=SEARCH_CND("id_consumption_goods_sector",1);
capital=SEARCH_CND("id_capital_goods_sector",1);
input=SEARCH_CND("id_intermediate_goods_sector",1);
energy=SEARCH_CND("id_energy_goods_sector",1);
government=SEARCH("GOVERNMENT");
financial=SEARCH("FINANCIAL");
external=SEARCH("EXTERNAL_SECTOR");
country=SEARCH("COUNTRY");
centralbank=SEARCH("CENTRAL_BANK");
aclass=SEARCH_CND("class_id",1);
bclass=SEARCH_CND("class_id",2);
cclass=SEARCH_CND("class_id",3);


	
PARAMETER
RESULT(0)