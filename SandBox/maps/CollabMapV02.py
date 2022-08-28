# CollabMapV02.py: Make a map showing research collaborators
# by Niall Madden, Aug 2022
# Mapping part based on 
# Based on https://towardsdatascience.com/using-python-to-create-a-world-map-from-a-list-of-country-names-cd7480d03b10
# Data file stored in Collabs1.xlsx

from geopy.geocoders import Nominatim
import pandas as pd
import folium
from folium.plugins import MarkerCluster

INFILE = 'Collaborators.xlsx'
OUTFILE = 'CollabMap.html'

Input_df = pd.read_excel(INFILE)
print(Input_df)

geolocator = Nominatim(user_agent="my-ap")

Home = geolocator.geocode("Galway, Ireland")

print(f"Starting from {[Home.longitude, Home.latitude]}")

Countries = Input_df['CountryName'].tolist()
Institutes = Input_df['Institution'].tolist()
Cities = Input_df['City'].tolist()

world_map= folium.Map(tiles="cartodbpositron", location=[Home.latitude, Home.longitude])
marker_cluster = MarkerCluster().add_to(world_map)
popup_text = "University of Galway"
folium.CircleMarker(location=[Home.latitude, Home.longitude],
                    tooltip=popup_text,popup=popup_text,
                    color="red", fill =True).add_to(marker_cluster)

for i in range(len(Cities)):
    city = Cities[i]
    inst = Institutes[i]
    country = Countries[i]
    place = inst+", "+city+", "+country
    location =  geolocator.geocode(place)
    if (location == None):
        print(f"*** Warning, could not find {place}. Trying {inst}")
        location =  geolocator.geocode(inst)
    if (location == None):
        print(f"*** Warning, could not find {inst}. Trying {city}")
        location =  geolocator.geocode(city)
    if (location == None):
        print(f"*** Warning, can't find {place} or {city} or {inst}")
        break
    lat = location.latitude
    lon = location.longitude
    print(f'{i}: Adding {inst} at ({lat},{lon})')
    popup_text = inst
    folium.CircleMarker(location = [lat,lon],  tooltip=popup_text,popup= popup_text, fill =True).add_to(marker_cluster)

world_map.fit_bounds(world_map.get_bounds(), padding=(30, 30))
world_map.save(outfile=OUTFILE)
