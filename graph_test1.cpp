/*Copyright (C)
 * 2019 - eda1 dot fiunam at yahoo dot com dot mx
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 */

#include <iostream>
// para cin, cout, cerr. (leer del teclado e imprimir en la pantalla)

#include <string>
// para declarar y procesar cadenas

#include <fstream>
// para usar archivos

#include "Vertex.hpp"
#include "Graph.hpp"

// esta versión dibuja grafos dirigidos
void draw_graph( Graph& g )
{
   std::string file_name = "mi_grafo.dot";

   std::fstream file;
   file.open( file_name, std::ios::out );

   if( not file ){
      std::cerr << "Error creando al archivo: " << file_name << std::endl;
      return;
   }


   std::map<std::string, Vertex> *vertices = g.get_vertices();
   // obtenemos la lista de vértices del grafo. Cada entrada en la lista es un
   // par <key,value>

   file << "digraph MiGrafo {\n";
   for( auto it = vertices->begin(); it != vertices->end(); ++it ){

      std::string name = it->first;
      // first es el equivalente a 'key', y la 'key' en esta tabla hash es el
      // nombre del nodo. También funciona:
      //
      //          std::string name = (it->second).get_name();

      std::list<Vertex> *neighbors = (it->second).get_neighbors();
      // obtenemos la lista de vecinos del vértice de trabajo

      for( auto& w : *(neighbors) ){
      	// Si el grafo es dirigido, hacer
         file << name << " -> " << w.get_name() << std::endl;

         // sino, hacer
         // file << name << " -- " << w.get_name() << std::endl;
      }
   }
   file << "}\n";


   file.close();
   std::cerr << "Generé el archivo: " << file_name;
   std::cerr << ", el cual deberá renderizar con el programa 'dot' de Linux.\n";
}

int main()
{
	std::array<std::string, 11> vertices = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K" };
	// std::array son como los arreglos estáticos nativos de C, [], pero con esteroides.
	// También existen los arreglos dinámicos: std::vector

	std::array<std::string, 11> edges = { "AE", "AB", "BC", "BF", "DH", "EI", "FG", "FI", "GJ", "GK", "HK" };
	// primero escribí las conexiones, luego las conté, y finalmente, escribí el '11'.
	// Como este ejemplo es de un grafo no dirigido, resulta que "AE" es lo mismo que
	// "EA", por eso no es necesario duplicar la conexión.

	Graph g;

	for( auto& v : vertices ){ g.add_vertex( Vertex( v ) ); }

	for( auto& e : edges ){ g.add_edge( e.substr( 0, 1 ), e.substr( 1, 1 ), Graph::Kind::DIRECTED ); }
	// .substr( a_partir_de_dónde, cuántos_queremos_leer )

	g.print();
	// imprime la estructura del grafo

	g.dfs( "A" );
	// ejecuta el algoritmo Depth-first search sobre el grafo g partiendo del vértice "A"

	draw_graph( g );
   // para usar esta función debes tener instalado el programa "dot", el cual
   // viene en el paquete graphviz:
   //
   //       $ sudo apt install graphviz
   //
   // Esta función genera un archivo mi_grafo.dot el cual tienes que renderizar
   // con el programa "dot". Para obtener una imagen del grafo en formato png:
   //
   //       $ dot -Tpng mi_grafo.dot -omi_grafo.png
   //
   // Pero si la quisieras como svg (más pequeña (en tamaño) y funcional):
   //
   //       $ dot -Tsvg mi_grafo.dot -omi_grafo.svg
   //

}
