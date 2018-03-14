<?php


Route::get('/', 'ClassController@index');

Route::get('/add', 'ClassController@add');

Route::post('add', 'ClassController@store');

Route::get('/addClass', 'ClassController@addClass');

Route::post('addClass', 'ClassController@storeClass');

Route::controllers([
    'auth' => 'Auth\AuthController',
    'password' => 'Auth\PasswordController',
]);