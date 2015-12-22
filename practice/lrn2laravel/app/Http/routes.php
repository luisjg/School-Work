<?php

Route::get('about', 'PagesController@about');

Route::get('contact', 'PagesController@contact');

Route::resource('articles', 'ArticlesController');

/*One way which is long and complex */
//
// Route::get('articles', 'ArticlesController@index');
//
// Route::get('articles/create', 'ArticlesController@create');
//
// Route::get('articles/{id}', 'ArticlesController@show');
//
// Route::post('articles', 'ArticlesController@store');
//
// Route::get('articles/{id}/edit', 'ArticlesController@edit');
