import 'package:flutter/material.dart';
import 'package:flutter/cupertino.dart';

void main() {
  runApp(
    MaterialApp(
      title: "shank",
      home: Scaffold(
        appBar: AppBar(
          title: Center(child: Text("The Flutter App")),
        ),
        body: MyHomePage(),
      ),
      // body:
    ),
  );
}

class MyHomePage extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return GridView.count(
      crossAxisCount: 3,
      // maxCrossAxisExtent: 200,
      mainAxisSpacing: 10,
      crossAxisSpacing: 2,
      children: [
        Image(image: AssetImage("images/1.png")),
        Image(image: AssetImage("images/2.png")),
        Image(image: AssetImage("images/3.png")),
        Image(image: AssetImage("images/4.png")),
        Image(image: AssetImage("images/5.png")),
      ],
    );
  }
}

// class MyHomePage extends StatelessWidget {
//   @override
//   Widget build(BuildContext context) {
//     return Container(
//       child: Image(image: AssetImage("images/1.png")),
//     );
//   }
// }

// class MyHomePage extends StatelessWidget {
//   @override
//   Widget build(BuildContext context) {
//     return Container(
//       child: ListView(
//         children: [
//           Container(
//               // padding: EdgeInsets.symmetric(vertical: 10),
//               margin: EdgeInsets.symmetric(vertical: 10, horizontal: 10),
//               // height: 1000,
//               decoration: BoxDecoration(color: Colors.black),
//               // child: Center(
//               //   child: Text(
//               //     "hi",
//               //     style: TextStyle(
//               //       fontSize: 20,
//               //       color: Colors.redAccent,
//               //     ),
//               //   ),
//               // ),
//               // child: Image(image: AssetImage("images/1.png")),
//               child: Image(
//                   image: NetworkImage(
//                       "https://cdn.pixabay.com/photo/2018/01/14/23/12/nature-3082832_960_720.jpg"),
//                   fit: BoxFit.fill)),
//           Container(
//             // padding: EdgeInsets.symmetric(vertical: 10),
//             margin: EdgeInsets.symmetric(vertical: 10, horizontal: 10),
//             // height: 1000,
//             decoration: BoxDecoration(color: Colors.black),
//             // child: Center(
//             //   child: Text(
//             //     "hi",
//             //     style: TextStyle(
//             //       fontSize: 20,
//             //       color: Colors.redAccent,
//             //     ),
//             //   ),
//             // ),
//             child: Image(image: AssetImage("images/2.png")),
//           ),
//         ],
//       ),
//     );
//   }
// }




// void main() {
//   runApp(MaterialApp(
//     title: "Awesome App",
//     home: Container(
//       color: Colors.red,
//     ),
//   ));
// }

// void main() {
//   runApp(MaterialApp(
//     title: "shank",
//     home: Container(
//       color: Colors.black,
//     ),
//   ));
// }


// class MyApp extends StatelessWidget {
//   @override
//   Widget build(BuildContext context) {
    // return Row(
    //   children: [
    //     Expanded(
    //       child: Text("One",
    //           textDirection: TextDirection.ltr, style: TextStyle(fontSize: 40)),
    //     ),
    //     Text("Two",
    //         textDirection: TextDirection.ltr, style: TextStyle(fontSize: 40)),
    //     Text("Three",
    //         textDirection: TextDirection.ltr, style: TextStyle(fontSize: 40)),
    //     Text("Three",
    //         textDirection: TextDirection.ltr, style: TextStyle(fontSize: 40)),
    //     Text("www",
    //         textDirection: TextDirection.ltr, style: TextStyle(fontSize: 40)),
    //   ],
    // );

    // return Column(children: <Widget>[
    //   Expanded(
    //       child: Text(
    //     "1",
    //     textDirection: TextDirection.ltr,
    //     style: TextStyle(fontSize: 100),
    //   )),
    //   Expanded(
    //       child: Text(
    //     "1",
    //     textDirection: TextDirection.ltr,
    //     style: TextStyle(fontSize: 100),
    //   )),
    // ]);

    // return Container(
    //   // padding: EdgeInsets.symmetric(vertical: 40, horizontal: 20),
    //   decoration: BoxDecoration(color: Colors.blueAccent),
    //   // padding: EdgeInsets.all(20.0),
    //   child: Column(children: [
    //     Expanded(
    //       child: Text(
    //         "name",
    //         textDirection: TextDirection.ltr,
    //         style: TextStyle(fontSize: 30),
    //       ),
    //     ),
    //   ]),
    // );

    // return Scaffold(
    //     // backgroundColor: Colors.redAccent,
    //     appBar: AppBar(
    //       backgroundColor: Colors.redAccent,
    //       title: Center(
    //         child: Text(
    //           "Flutter App",
    //           style: TextStyle(
    //             fontSize: 50,
    //             color: Colors.greenAccent,
    //           ),
    //         ),
    //       ),
    //     ),
    //     body: Container(child: Text("hello"))
    //     // Image(
    //     //   image: AssetImage("images/1.png"),
    //     // ),
    //     );


    // Container(
    //   color: Colors.pinkAccent,
    //   child: ListView(
    //     children: [
    //       //
    //       Container(
    //         // margin: EdgeInsets.only(left: 20, right: 70),
    //         margin: EdgeInsets.symmetric(horizontal: 10, vertical: 50),
    //         // padding: EdgeInsets.symmetric(vertical: 10, horizontal: 10),
    //         color: Colors.blueAccent,
    //         child: Center(
    //           child: Text(
    //             "gagan",
    //             style: TextStyle(
    //               fontSize: 50,
    //               color: Colors.redAccent,
    //               // decoration: BoxDecoration(color: Colors.blueAccent),
    //             ),
    //           ),
    //         ),
    //       ),
    //       //
    //     ],
    //   ),
    // ),

    // return Directionality(
    //     textDirection: TextDirection.ltr,
    //     child: ListView(children: [
    //       Container(
    //         height: 200,
    //         // padding: EdgeInsets.symmetric(vertical: 50),
    //         // color: Colors.blueAccent,
    //         decoration: BoxDecoration(color: Colors.orangeAccent),
    //         // color: Colors.greenAccent,
    //         child: Center(
    //           child: Text(
    //             "shank",
    //             textDirection: TextDirection.ltr,
    //             style: TextStyle(
    //               fontSize: 20,
    //               decoration: TextDecoration.none,
    //               color: Colors.blue,
    //             ),
    //           ),
    //         ),
    //       ),
    //       Container(
    //         height: 200,
    //         color: Colors.greenAccent,
    //         child: Center(
    //           child: Text(
    //             "shank",
    //             textDirection: TextDirection.ltr,
    //             style: TextStyle(fontSize: 20),
    //           ),
    //         ),
    //       ),
    //       Container(
    //         height: 200,
    //         color: Colors.pinkAccent,
    //         child: Center(
    //           child: Text(
    //             "shank",
    //             textDirection: TextDirection.ltr,
    //             style: TextStyle(fontSize: 20),
    //           ),
    //         ),
    //       ),
    //       Container(
    //         height: 200,
    //         color: Colors.yellowAccent,
    //         child: Center(
    //           child: Text(
    //             "shank",
    //             textDirection: TextDirection.ltr,
    //             style: TextStyle(fontSize: 20),
    //           ),
    //         ),
    //       ),
    //     ]));

    // Container(
    // child: Text("hello", style: TextStyle(fontSize: 100)),
    // color: Colors.pink,

    // appBar:AppBar(title:Text("this is heading"),),
    // );


// void main() {
//   runApp(MaterialApp(title: "shank", home: MyNewApp()));
// runApp(Text("hi flutter",
//     textDirection: TextDirection.ltr, style: TextStyle(fontSize: 90)));
// }

// class MyNewApp extends StatelessWidget {
//   @override
//   Widget build(BuildContext context) {
//     // return Container(color: Colors.green, child: Text("hi"));
//     return Scaffold(
//         appBar: AppBar(
//           title: Center(
//             child: Text("This is heading"),
//           ),
//         ),
//         body: Container(
//           color: Colors.indigo,
//           child: Center(child: Text("work done")),
//         ));
//   }
// }

// void main() {
//   runApp(MaterialApp(
//       title: "Awesome App 123",
// home: Container(
//   color: Colors.blue,
// ),
//       home: HomePage()));
// }

// class HomePage extends StatelessWidget {
//   @override
//   Widget build(BuildContext context) {
//     // return Container(
//     //   color: Colors.red,
//     //   child: Text("hello"),
//     // );
//     return Scaffold(
//         appBar: AppBar(
//           title: Text("Hello Guys"),
//         ),
//         // body: Container(
//         //   child: Center(child: Text("Hello Flutter")),
//         //   color: Colors.red,
//         // ));
//         body: Center(
//             child: Container(
//           alignment: Alignment.center,
//           padding: const EdgeInsets.all(10),
//           width: 100,
//           height: 100,
//           // color: Colors.teal,
//           decoration: BoxDecoration(
//               shape: BoxShape.rectangle,
//               borderRadius: BorderRadius.circular(10),
//               color: Colors.red,
//               gradient: LinearGradient(colors: [Colors.pink, Colors.blue])),
//           child: Text("Hello Guys"),
//         )));
//   }
// }
