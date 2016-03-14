module unitro.network;

import unitro.world;
import unitro.config;

/++
++/
class Network{
	public{
		this(Config config){
			_world = new World(config);
		}
		
		void setPlayerEvent(){
			//...
			sync;
		}
		
		void setLocalWorld(){
			//...
			sync;
		};
		
		void  getLocalWorld(){
			sync;
			//...
		}
	}//public

	private{
		World _world;
			
		void sync(){};
	}//private
}//class Network
