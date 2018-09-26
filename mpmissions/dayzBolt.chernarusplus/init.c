void main()
{
	Hive ce = CreateHive();
	if ( ce )
		ce.InitOffline();

	Weather weather = g_Game.GetWeather();

	/*
	weather.GetOvercast().SetLimits( 0.0 , 1.0 );
	weather.GetRain().SetLimits( 0.0 , 1.0 );
	weather.GetFog().SetLimits( 0.0 , 0.25 );
	*/
	
	weather.GetOvercast().SetLimits( 1.1 , 5.0 );
	weather.GetRain().SetLimits( 0.0 , 1.0 );
	weather.GetFog().SetLimits( 0.25 , 5.0 );
	
	weather.GetOvercast().SetForecastChangeLimits( 0.0, 0.2 );
	weather.GetRain().SetForecastChangeLimits( 0.0, 0.1 );
	weather.GetFog().SetForecastChangeLimits( 0.15, 0.45 );

	weather.GetOvercast().SetForecastTimeLimits( 1800 , 1800 );
	weather.GetRain().SetForecastTimeLimits( 600 , 600 );
	weather.GetFog().SetForecastTimeLimits( 1800 , 1800 );

	weather.GetOvercast().Set( Math.RandomFloatInclusive(0.0, 0.3), 0, 0);
	weather.GetRain().Set( Math.RandomFloatInclusive(0.0, 0.2), 0, 0);
	weather.GetFog().Set( Math.RandomFloatInclusive(0.0, 0.1), 0, 0);
	
	weather.SetWindMaximumSpeed(35);
	weather.SetWindFunctionParams(0.1, 0.3, 50);

}

class CustomMission: MissionServer
{	
	protected bool m_bLoaded = false;

	void SetRandomHealth(EntityAI itemEnt)
	{
		int rndHlt = 100;
		itemEnt.SetHealth("","",rndHlt);
	}

	override PlayerBase CreateCharacter(PlayerIdentity identity, vector pos, ParamsReadContext ctx, string characterName)
	{
		Entity playerEnt;
		playerEnt = GetGame().CreatePlayer(identity, characterName, pos, 0, "NONE"); //Creates random player
		Class.CastTo(m_player, playerEnt);
		
		GetGame().SelectPlayer(identity, m_player);
		
		return m_player;
	}

	override void OnUpdate( float timeslice )
	{
		super.OnUpdate( timeslice );

        if( !m_bLoaded && !GetDayZGame().IsLoading() )
        {
            m_bLoaded = true;
        }
	}

	void SetHealth(EntityAI itemEnt, int health)
	{
		itemEnt.SetHealth("","",health);
	}

	override void StartingEquipSetup(PlayerBase player, bool clothesChosen)
	{
/*
		player.RemoveAllItems();

		EntityAI item = player.GetInventory().CreateInInventory(topsArray.GetRandomElement());
		EntityAI item2 = player.GetInventory().CreateInInventory(pantsArray.GetRandomElement());
		EntityAI item3 = player.GetInventory().CreateInInventory(shoesArray.GetRandomElement());
*/

		player.RemoveAllItems();

		EntityAI itemEnt;
		ItemBase itemBs;
		
		itemEnt = player.GetInventory().CreateInInventory("Ushanka_Black");
		itemBs = ItemBase.Cast(itemEnt);
		SetHealth(itemEnt, 20);

		itemEnt = player.GetInventory().CreateInInventory("BomberJacket_Black");
		itemBs = ItemBase.Cast(itemEnt);
		SetHealth(itemEnt, 40);

		itemEnt = player.GetInventory().CreateInInventory("Jeans_Black");
		itemBs = ItemBase.Cast(itemEnt);	
		SetHealth(itemEnt, 20);

		itemEnt = player.GetInventory().CreateInInventory("HikingBoots_Brown");
		itemBs = ItemBase.Cast(itemEnt);	
		SetHealth(itemEnt, 20);

		itemEnt = player.GetInventory().CreateInInventory("Hatchet");
		itemBs = ItemBase.Cast(itemEnt);	
		SetHealth(itemEnt, 20);

/*
		itemEnt = player.GetInventory().CreateInInventory("SmershBag");
		itemBs = ItemBase.Cast(itemEnt);

		itemEnt = player.GetInventory().CreateInInventory("NBCHoodGray");
		itemBs = ItemBase.Cast(itemEnt);	

		itemEnt = player.GetInventory().CreateInInventory("SteakKnife");
		itemBs = ItemBase.Cast(itemEnt);

		itemEnt = player.GetInventory().CreateInInventory("OrienteeringCompass");
		itemBs = ItemBase.Cast(itemEnt);

		itemEnt = player.GetInventory().CreateInInventory("BandageDressing");
		itemBs = ItemBase.Cast(itemEnt);
*/
/*
		EntityAI oCar = EntityAI.Cast(GetGame().CreateObject("OffroadHatchback", player.GetPosition(), false, true)); 

		oCar.GetInventory().CreateAttachment("HatchbackWheel"); 
		oCar.GetInventory().CreateAttachment("HatchbackWheel"); 
		oCar.GetInventory().CreateAttachment("HatchbackWheel"); 
		oCar.GetInventory().CreateAttachment("HatchbackWheel"); 
		oCar.GetInventory().CreateAttachment("HatchbackWheel"); 
		oCar.GetInventory().CreateAttachment("HatchbackDoors_Driver"); 
		oCar.GetInventory().CreateAttachment("HatchbackDoors_CoDriver"); 
		oCar.GetInventory().CreateAttachment("HatchbackTrunk"); 
		oCar.GetInventory().CreateAttachment("HatchbackHood"); 
		oCar.GetInventory().CreateAttachment("SparkPlug"); 
		oCar.GetInventory().CreateAttachment("EngineBelt"); 
		oCar.GetInventory().CreateAttachment("CarRadiator"); 
		oCar.GetInventory().CreateAttachment("CarBattery"); 
		oCar.SetAllowDamage(false);
*/

	}
};
  
Mission CreateCustomMission(string path)
{
	return new CustomMission();
}