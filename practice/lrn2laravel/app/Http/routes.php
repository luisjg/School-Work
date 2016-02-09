<?php
Route::get('/', 'PagesController@index');

Route::get('blog', 'PagesController@blog');

Route::get('contact', 'PagesController@contact');

Route::get('projects', 'PagesController@projects');

Route::resource('articles', 'ArticlesController');

// less explicit
Route::controllers([
	'auth' => 'Auth\AuthController',
	'password' => 'Auth\PasswordController',
	]);
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
